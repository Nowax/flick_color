#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "src/log/logger.h"
#include "color_palette.h"
#include "view.h"
#include <boost/optional.hpp>

namespace Ui {
class main_window;
}

typedef std::shared_ptr<class color_palette> palette_t;
typedef std::shared_ptr<class logger> logger_t;

class main_window : public QMainWindow, public view
{
	Q_OBJECT

public:
	explicit main_window(palette_t p, QWidget *parent = 0);
	~main_window();

	void update(matrix_t new_palette);
	void announce_victory();

private slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

	void on_pushButton_5_clicked();

	void on_pushButton_6_clicked();

private:
	Ui::main_window *ui;
	logger_t logger_h;
	palette_t palette;
	int turns_counter;
	void prepare_palette_view();
	void iterate_turns_counter();
	void response_for_clicked_button(const char new_dominant_color);
	void prepare_color_buttons();
	boost::optional<QColor> find_color(const char char_color) const;
};

#endif // MAIN_WINDOW_H
