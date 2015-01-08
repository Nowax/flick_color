#include "rule_keeper.h"

rule_keeper::rule_keeper() :
	model_observer(),
	me(std::shared_ptr<class rule_keeper>(this)),
	logger_h(logger_t(new logger(std::string("rule_keeper"))))
{
}

rule_keeper::~rule_keeper()
{
	if (observed_palette_handler) {
		logger_h->log_debug("Detaching observer (rule_keeper).");
		observed_palette_handler->detach(me);
	}
}

void rule_keeper::subscribe(std::shared_ptr<class color_palette> palette)
{
	if (!observed_palette_handler) {
		observed_palette_handler = palette;
		observed_palette_handler->attach(me);
		update(palette);
		logger_h->log_info("Pallete observer subscribed.");
	} else {
		logger_h->log_warning("Pallete observer already subscribed.");
	}
}

void rule_keeper::add_view(view_t new_view)
{
	view_h = new_view;
}

void rule_keeper::update(std::shared_ptr<model> color_palette)
{
	if (color_palette == observed_palette_handler) {
		matrix_t p = observed_palette_handler->get_current_palette();
		if (view_h) {
			if (is_it_victory(p)) {
				view_h->announce_victory();
			}
		} else {
			logger_h->log_warning("View object not initialized yet.");
		}
	}
}

bool rule_keeper::is_it_victory(matrix_t palette)
{
	char inspected_color = palette[0][0].first;

	for (auto &row : palette) {
		for (auto &cell : row) {
			if (cell.first != inspected_color) {
				logger_h->log_debug("Not victory yet.");
				return false;
			}
		}
	}

	logger_h->log_info("Victory.");
	return true;
}
