#include "color_palette.h"

color_palette::color_palette(gen_main_window_t mw) :
    palette(0)
{
    connect(*mw, SIGNAL(refresh_pallete), this, SLOT(change_palette(int)));
}

void color_palette::change_palette(int val)
{
    palette = val;
    notify_change(palette);
}
