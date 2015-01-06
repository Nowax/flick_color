#include "main_window.h"
#include "ui_main_window.h"
#include <QDebug>

main_window::main_window(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::main_window),
	logger_h(logger_t(new logger(std::string("main_window"))))
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
	qDebug() << changed_element;
	ui->label->setText(QString::number(changed_element));
}

void main_window::on_spinBox_valueChanged(int new_val)
{
	emit refresh_palette(new_val);
}
