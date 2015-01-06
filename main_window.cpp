#include "main_window.h"
#include "ui_main_window.h"
#include <QDebug>

main_window::main_window(palette_t p, QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::main_window),
	logger_h(logger_t(new logger(std::string("main_window")))),
	palette(p)
{
	logger_h->log_debug("Main window successfully created.");
	ui->setupUi(this);
}

main_window::~main_window()
{
	logger_h->log_debug("Deletion of main window");
	delete ui;
}

void main_window::update(int changed_element)
{
	logger_h->log_debug("Label is updated with value " + std::to_string(changed_element));
	ui->label->setText(QString::number(changed_element));
}

void main_window::on_spinBox_valueChanged(int new_val)
{
	logger_h->log_debug("SpinBox1 value has been changed to " + std::to_string(new_val));
	palette->set_dominant_color(new_val);
}

void main_window::on_spinBox_2_valueChanged(int arg1)
{
	logger_h->log_debug("SpinBox2 value has been changed to " + std::to_string(arg1));
	palette->set_dominant_color(arg1);
}
