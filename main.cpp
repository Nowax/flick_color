#include "main_window.h"
#include "color_palette.h"
#include "model_observer.h"
#include "color_palette_observer.h"
#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	auto w = std::shared_ptr<class main_window>(new main_window);
	auto c_palette = std::shared_ptr<class color_palette>(new color_palette(w));
	auto palette_observer = std::shared_ptr<class color_palette_observer>(new color_palette_observer());

	palette_observer->subscribe(c_palette);

    w->show();

    return a.exec();
}
