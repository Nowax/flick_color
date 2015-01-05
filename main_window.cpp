#include "main_window.h"
#include "ui_main_window.h"
#include <QDebug>

main_window::main_window(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::main_window)
{
	ui->setupUi(this);
}

main_window::~main_window()
{
	delete ui;
}

void main_window::update(int changed_element)
{
	qDebug() << changed_element;
	ui->label->setText(QString::number(changed_element));
}

void main_window::on_spinBox_valueChanged(int arg1)
{
	emit refresh_palette(arg1);
}
