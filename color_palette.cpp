#include "color_palette.h"

color_palette::color_palette(std::shared_ptr<class main_window> main_window) :
	color_handler(0)
{
//	connect(main_window.get(), SIGNAL(refresh_pallete(int)), this, SLOT(change_palette(int)));
}

void color_palette::change_palette(int val)
{
	color_handler = val;
	notify_change();
}

int color_palette::get_dominant_color()
{
	return color_handler;
}

void color_palette::set_dominant_color(int new_val)
{
	color_handler = new_val;
}
