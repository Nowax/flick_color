#include "color_palette.h"

color_palette::color_palette() :
	color_handler(0),
	logger_h(logger_t(new logger(std::string("color_palette"))))
{
	logger_h->log_info("Color palette successfuly created.");
}

void color_palette::change_palette(int val)
{
	logger_h->log_debug("Palette has been changed - change notification send.");
	color_handler = val;
	notify_change();
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
