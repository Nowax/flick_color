#ifndef PALETTE_CONTROLLER_H
#define PALETTE_CONTROLLER_H

#include "logger/logger.h"
#include "controller.h"
#include <memory>

typedef std::shared_ptr<class logger> logger_t;

class palette_controller : public controller
{
public:
	palette_controller();

	void subscribe_model(std::shared_ptr<model> new_model);
	void subscribe_view(std::shared_ptr<view> new_view);

private:
	logger_t logger_h;

};

#endif // PALETTE_CONTROLLER_H
