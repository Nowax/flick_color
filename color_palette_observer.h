#ifndef COLOR_PALETTE_OBSERVER_H
#define COLOR_PALETTE_OBSERVER_H

#include "model_observer.h"
#include "color_palette.h"
#include "logger.h"

typedef std::shared_ptr<class logger> logger_t;

class color_palette_observer : public model_observer
{
public:
    color_palette_observer();
	~color_palette_observer();

	virtual void update(std::shared_ptr<class model> color_palette);
	void subscribe(std::shared_ptr<color_palette> palette);

private:
	std::shared_ptr<class color_palette> observed_palette_handler;
	std::shared_ptr<class color_palette_observer> me;
	logger_t logger_h;

};

#endif // COLOR_PALETTE_OBSERVER_H
