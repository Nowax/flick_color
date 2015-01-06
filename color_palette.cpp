#include "color_palette.h"
#include <vector>
#include <boost/assign.hpp>
#include <algorithm>

color_palette::color_palette() :
	color_handler(0),
	logger_h(logger_t(new logger(std::string("color_palette"))))
{
	initialize_palette();
	assign_colors();
	logger_h->log_info("Color palette successfuly created.");
}

void color_palette::initialize_palette()
{
	matrix_t p(consts::palette_size);

	for (auto &raw : p) {
		raw.resize(consts::palette_size);
	}
	palette = p;
}

void color_palette::assign_colors()
{
	std::vector<char> shuffled_colors(consts::colors);
	std::string row_print;

	for (auto &row : palette) {
		for (auto &cell : row) {
			std::random_shuffle(shuffled_colors.begin(), shuffled_colors.end());
			cell = shuffled_colors.front();
			row_print.push_back(cell);
		}
		logger_h->log_debug(row_print);
		row_print.clear();
	}
}

void color_palette::change_palette(int val)
{
	logger_h->log_debug("Palette has been changed - change notification send.");
	color_handler = val;
	notify_change();
}

matrix_t color_palette::get_current_palette()
{
	return palette;
}

int color_palette::get_dominant_color()
{
	return color_handler;
}

void color_palette::set_dominant_color(int new_val)
{
	logger_h->log_debug("New dominant color was set to " + std::to_string(new_val));
	color_handler = new_val;
	notify_change();
}
