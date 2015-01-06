#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "logger.h"
#include "color_palette.h"

namespace Ui {
class main_window;
}

typedef std::shared_ptr<class color_palette> palette_t;
typedef std::shared_ptr<class logger> logger_t;

class main_window : public QMainWindow
{
	Q_OBJECT

public:
	explicit main_window(palette_t p, QWidget *parent = 0);
	~main_window();

	void update(int changed_element);

private slots:
	void on_spinBox_valueChanged(int new_val);

	void on_spinBox_2_valueChanged(int arg1);

private:
	Ui::main_window *ui;
	logger_t logger_h;
	palette_t palette;
};

#endif // MAIN_WINDOW_H
