#include "color_palette.h"
#include <vector>
#include <boost/assign.hpp>
#include <algorithm>
#include <utility>

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
			cell.first = shuffled_colors.front();
			row_print.push_back(cell.first);
		}
		logger_h->log_debug(row_print);
		row_print.clear();
	}

	color_handler = palette[0][0].first;
}

void color_palette::refresh_cells_chain_state()
{
	std::string row_chain_state;

	for (auto &row : palette) {
		for (auto &cell : row) {
			if (cell.first == color_handler) {
				cell.second = true;
				row_chain_state.push_back('X');
			} else {
				cell.second = false;
				row_chain_state.push_back('O');
			}
		}
		logger_h->log_debug(row_chain_state);
		row_chain_state.clear();
	}
}

void color_palette::change_palette(char new_dominant)
{
	logger_h->log_debug("Palette has been changed - change notification send.");
	apply_new_dominant_color(new_dominant);
}

void color_palette::apply_new_dominant_color(char new_dominant)
{
	palette[0][0].first = new_dominant;
	palette[0][0].second = true;

	for (int row = 0; row < consts::palette_size; row++) {
		for (int col = 0; col < consts::palette_size; col++) {
			if (palette[row][col].first == color_handler
				&& is_connected_to_chain(std::make_pair(row,col))) {
				palette[row][col].first = new_dominant;
				palette[row][col].second = true;
			}
		}
	}
}

std::vector<int> color_palette::define_offset(std::pair<int, int> index)
{
	int plus_row_offset = 1,
		minus_row_offset = -1,
		plus_col_offset = 1,
		minus_col_offset = -1;

	if (index.first == 0 ) {
		minus_row_offset = 0;
	} else if (index.first == consts::palette_size - 1) {
		plus_row_offset = 0;
	}

	if (index.second == 0) {
		minus_col_offset = 0;
	} else if (index.second == consts::palette_size - 1) {
		plus_col_offset = 0;
	}

	std::vector<int> offsets = boost::assign::list_of
			(plus_row_offset)
			(minus_row_offset)
			(plus_col_offset)
			(minus_col_offset);

	return offsets;
}

bool color_palette::is_connected_to_chain(std::pair<int, int> index)
{
	std::vector<int> offsets = define_offset(index);

	if (offsets[0] != 0 && palette[index.first + offsets[0]][index.second].second == true) {
		return true;
	}
	if (offsets[1] != 0 && palette[index.first + offsets[1]][index.second].second == true) {
		return true;
	}
	if (offsets[2] != 0 && palette[index.first][index.second + offsets[2]].second == true) {
		return true;
	}
	if (offsets[3] != 0 && palette[index.first][index.second + offsets[3]].second == true) {
		return true;
	}

	return false;
}

matrix_t color_palette::get_current_palette()
{
	return palette;
}

int color_palette::get_dominant_color()
{
	return color_handler;
}

void color_palette::set_dominant_color(char new_val)
{
	change_palette(new_val);
	color_handler = new_val;
	logger_h->log_debug("New dominant color was set to " + std::to_string(new_val));
	notify_change();
}
