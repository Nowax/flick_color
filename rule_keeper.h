#ifndef RULE_KEEPER_H
#define RULE_KEEPER_H

#include "model_observer.h"
#include "color_palette.h"
#include "logger/logger.h"
#include "view.h"
#include "main_window.h"

typedef std::shared_ptr<class logger> logger_t;
typedef std::shared_ptr<class main_window> main_window_t;
typedef std::shared_ptr<class view> view_t;
typedef std::vector<std::vector<std::pair<char, bool>>> matrix_t;

class rule_keeper : public model_observer
{
public:
	rule_keeper();
	~rule_keeper();

	virtual void update(std::shared_ptr<class model> color_palette);
	void subscribe(std::shared_ptr<color_palette> palette);
	void add_view(view_t new_view);

private:
	std::shared_ptr<class color_palette> observed_palette_handler;
	std::shared_ptr<class rule_keeper> me;
	logger_t logger_h;
	view_t view_h;
	bool is_it_victory(matrix_t palette);
};

#endif // RULE_KEEPER_H
