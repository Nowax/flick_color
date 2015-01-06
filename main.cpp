#include "main_window.h"
#include "color_palette.h"
#include "model_observer.h"
#include "color_palette_observer.h"
#include <QApplication>
#include <memory>
#include <stdio.h>
#include "common_consts.h"

void prepare_env()
{
	remove(consts::log::log_name.c_str());
}

int main(int argc, char *argv[])
{
	prepare_env();

	QApplication a(argc, argv);

	auto w = std::shared_ptr<class main_window>(new main_window);
	auto c_palette = std::shared_ptr<class color_palette>(new color_palette(w));
	std::weak_ptr<class color_palette> wp_palette = c_palette;
	auto palette_observer = std::shared_ptr<class color_palette_observer>(new color_palette_observer());

	palette_observer->subscribe(wp_palette.lock());
	palette_observer->subscribe(c_palette);

	w->show();

	return a.exec();
}
