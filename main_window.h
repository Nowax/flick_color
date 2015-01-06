#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "logger.h"

namespace Ui {
class main_window;
}

typedef std::shared_ptr<class logger> logger_t;

class main_window : public QMainWindow
{
	Q_OBJECT

public:
	explicit main_window(QWidget *parent = 0);
	~main_window();

	void update(int changed_element);

signals:
	void refresh_palette(int val);

private slots:
	void on_spinBox_valueChanged(int new_val);

private:
	Ui::main_window *ui;
	logger_t logger_h;
};

#endif // MAIN_WINDOW_H
