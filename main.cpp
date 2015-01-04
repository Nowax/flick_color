#include "gen_main_window.h"
#include "color_palette.h"
#include <QApplication>
#include <boost/shared_ptr.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto w = boost::shared_ptr<gen_main_window>(new gen_main_window);
    auto color_palette_model = boost::shared_ptr<color_palette>(new color_palette(w));
    color_palette_model->attach(w);
    w->show();

    return a.exec();
}
