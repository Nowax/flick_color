#include "main_window.h"
#include "ui_main_window.h"
#include <QDebug>
#include <qstandarditemmodel.h>
#include <algorithm>
#include <QMessageBox>

main_window::main_window(palette_t p, QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::main_window),
	logger_h(logger_t(new logger(std::string("main_window")))),
	palette(p),
	turns_counter(0)
{
	logger_h->log_debug("Main window successfully created.");
	ui->setupUi(this);
	prepare_palette_view();
	ui->label->setText(QString::number(turns_counter));
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
	ui->tableView->verticalHeader()->setDefaultSectionSize(1.5*ui->tableView->fontMetrics().height());
	ui->tableView->horizontalHeader()->setDefaultSectionSize(1.5*ui->tableView->fontMetrics().height());
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
//			model->setData(index, QVariant(QBrush(QColor(0,10,67))),Qt::BackgroundRole);
			model->setData(index, QChar(new_palette[row][col].first));
		}
	}
	ui->tableView->setModel(model);
	ui->tableView->verticalHeader()->hide();
	ui->tableView->horizontalHeader()->hide();
	ui->tableView->adjustSize();
}

void main_window::on_pushButton_clicked()
{
	logger_h->log_debug("# button clicked.");
	iterate_turns_counter();
	palette->set_dominant_color('#');
}

void main_window::on_pushButton_2_clicked()
{
	logger_h->log_debug("$ button clicked.");
	iterate_turns_counter();
	palette->set_dominant_color('$');
}

void main_window::on_pushButton_3_clicked()
{
	logger_h->log_debug("X button clicked.");
	iterate_turns_counter();
	palette->set_dominant_color('X');
}

void main_window::on_pushButton_4_clicked()
{
	logger_h->log_debug("| button clicked.");
	iterate_turns_counter();
	palette->set_dominant_color('|');
}

void main_window::on_pushButton_5_clicked()
{
	logger_h->log_debug("@ button clicked.");
	iterate_turns_counter();
	palette->set_dominant_color('@');
}

void main_window::on_pushButton_6_clicked()
{
	logger_h->log_debug("? button clicked.");
	iterate_turns_counter();
	palette->set_dominant_color('?');
}

void main_window::iterate_turns_counter()
{
	ui->label->setText(QString::number(++turns_counter));
}

void main_window::announce_victory()
{
	QMessageBox msgBox;
	QString message = "Congratulation! You've just won!";
	msgBox.information(this,"Victory!",message,QMessageBox::Ok);
}
