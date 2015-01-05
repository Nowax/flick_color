#ifndef PALETTE_CONTROLLER_H
#define PALETTE_CONTROLLER_H

#include "color_palette.h"
#include <memory>

class palette_controller
{
public:
	palette_controller(std::shared_ptr<class color_palette> p);

private:
	std::shared_ptr<class color_palette> palette_handler;
};

#endif // PALETTE_CONTROLLER_H
