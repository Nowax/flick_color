#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

namespace Ui {
class main_window;
}

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
	void on_spinBox_valueChanged(int arg1);

private:
	Ui::main_window *ui;
};

#endif // MAIN_WINDOW_H
