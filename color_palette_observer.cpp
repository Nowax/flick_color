#include "color_palette_observer.h"
#include <QDebug>

color_palette_observer::color_palette_observer() :
	model_observer(),
	me(std::shared_ptr<class color_palette_observer>(this)),
	logger_h(logger_t(new logger(std::string("color_pallete_observer"))))
{
}

color_palette_observer::~color_palette_observer()
{
	if (observed_palette_handler) {
		//FIXME segfault
		observed_palette_handler->detach(me);
	}
}

void color_palette_observer::subscribe(std::shared_ptr<class color_palette> palette)
{
	if (!observed_palette_handler) {
		observed_palette_handler = palette;
		observed_palette_handler->attach(me);
		logger_h->log_info("Pallete observer subscribed.");
	} else {
		logger_h->log_warning("Pallete observer already subscribed.");
	}
}

void color_palette_observer::update(std::shared_ptr<model> color_palette)
{
	if (color_palette == observed_palette_handler) {
		//DO ACTION - as a response for change notify
		int color = observed_palette_handler->get_dominant_color();

		qDebug() << QString::number(color);
	}
}
