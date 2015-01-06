#include "main_window.h"
#include "ui_main_window.h"
#include <QDebug>
#include <qstandarditemmodel.h>
#include <algorithm>

main_window::main_window(palette_t p, QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::main_window),
	logger_h(logger_t(new logger(std::string("main_window")))),
	palette(p)
{
	logger_h->log_debug("Main window successfully created.");
	ui->setupUi(this);
	prepare_palette_view();
}

main_window::~main_window()
{
	logger_h->log_debug("Deletion of main window");
	delete ui;
}

void main_window::prepare_palette_view()
{
	logger_h->log_debug("Preparing palette view.");
	QStandardItemModel *model = new QStandardItemModel(
				consts::palette_size,consts::palette_size,this);
	for (int column = 0; column < consts::palette_size; column++) {
		model->setHorizontalHeaderItem(column, new QStandardItem(QString::number(column+1)));
	}
	ui->tableView->setModel(model);
}

void main_window::update(matrix_t new_palette)
{
	logger_h->log_debug("Updating palette...");
	QStandardItemModel *model = new QStandardItemModel(
				consts::palette_size,consts::palette_size,this);

	for (int row = 0; row < consts::palette_size; row++) {
		for (int col = 0; col < consts::palette_size; col++) {
			QModelIndex index
				= model->index(row,col,QModelIndex());
			model->setData(index, QChar(new_palette[row][col]));
		}
	}
	ui->tableView->setModel(model);
}

void main_window::on_spinBox_valueChanged(int new_val)
{
	logger_h->log_debug("SpinBox1 value has been changed to " + std::to_string(new_val));
	palette->set_dominant_color(new_val);
//	my_model->set_dominant_color(new_val);
}

void main_window::on_spinBox_2_valueChanged(int arg1)
{
	logger_h->log_debug("SpinBox2 value has been changed to " + std::to_string(arg1));
	palette->set_dominant_color(arg1);
}
