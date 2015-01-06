#include "palette_controller.h"

palette_controller::palette_controller() :
	logger_h(logger_t(new logger(std::string("palette_controller"))))
{
	logger_h->log_debug("Palette controller successfully created.");
}

void palette_controller::on_spinBox_valueChanged(int new_val)
{
	logger_h->log_debug("SpinBox value has been changed");
}

void palette_controller::subscribe_model(std::shared_ptr<class model> new_model)
{
	logger_h->log_info("Model successfully subscribed to controller.");
	my_model = new_model;
}

void palette_controller::subscribe_view(std::shared_ptr<class view> new_view)
{
	logger_h->log_info("View successfully subscibed to controller.");
	my_view = new_view;
}
