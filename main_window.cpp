#include "main_window.h"
#include "ui_main_window.h"
#include <QDebug>
#include <qstandarditemmodel.h>
#include <algorithm>
#include <QMessageBox>
#include <boost/assign.hpp>

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
	prepare_color_buttons();
	ui->label->setText(QString::number(turns_counter));
}

main_window::~main_window()
{
	logger_h->log_debug("Deletion of main window");
	delete ui;
}

void main_window::prepare_palette_view()
{
	QStandardItemModel *model = new QStandardItemModel(
				consts::palette_size,consts::palette_size,this);
	for (int column = 0; column < consts::palette_size; column++) {
		model->setHorizontalHeaderItem(column, new QStandardItem(QString::number(column+1)));
	}
	ui->tableView->setModel(model);
	ui->tableView->verticalHeader()->setDefaultSectionSize(1.5*ui->tableView->fontMetrics().height());
	ui->tableView->horizontalHeader()->setDefaultSectionSize(1.5*ui->tableView->fontMetrics().height());
	logger_h->log_debug("Palette view initialized correctely");
}

void main_window::prepare_color_buttons()
{
	std::vector<QPushButton*> buttons = boost::assign::list_of
			(ui->pushButton)
			(ui->pushButton_2)
			(ui->pushButton_3)
			(ui->pushButton_4)
			(ui->pushButton_5)
			(ui->pushButton_6);

	unsigned int next_color = 0;
	for (auto &button : buttons) {
		if (next_color < consts::colors.size()) {
			boost::optional<QColor> color = find_color(consts::colors[next_color]);
			if (color != boost::none) {
				button->setStyleSheet(QString::fromStdString("QPushButton {background-color: ")
										+ color.get().name()
										+ QString::fromStdString(";}"));
				button->show();
			} else {
				return;
			}
		} else {
			logger_h->log_error("Nuber of colors are diffrent from number of buttons.");
			return;
		}
		next_color++;
	}
	logger_h->log_info("All button initialized correctely.");
}

boost::optional<QColor> main_window::find_color(const char char_color) const
{
	auto char_rgb_pair = consts::char_to_rgb_color_map.find(char_color);
	if (char_rgb_pair != consts::char_to_rgb_color_map.end()) {
		return char_rgb_pair->second;
	} else {
		logger_h->log_error("There is no " + std::string({char_color}) + " color defined in constants.");
		return boost::optional<QColor>();
	}
}

void main_window::update(matrix_t new_palette)
{
	logger_h->log_debug("Updating palette...");
	QStandardItemModel *model = new QStandardItemModel(
				consts::palette_size,consts::palette_size,this);

	for (int row = 0; row < consts::palette_size; row++) {
		for (int col = 0; col < consts::palette_size; col++) {
			QModelIndex index = model->index(row,col,QModelIndex());
			boost::optional<QColor> color = find_color(new_palette[row][col].first);
			if (color != boost::none) {
				model->setData(index, QVariant(QBrush(color.get())),Qt::BackgroundRole);
			}
		}
	}
	ui->tableView->setModel(model);
	ui->tableView->verticalHeader()->hide();
	ui->tableView->horizontalHeader()->hide();
	ui->tableView->adjustSize();
}

void main_window::on_pushButton_clicked()
{
	response_for_clicked_button(consts::colors[0]);
}

void main_window::on_pushButton_2_clicked()
{
	response_for_clicked_button(consts::colors[1]);
}

void main_window::on_pushButton_3_clicked()
{
	response_for_clicked_button(consts::colors[2]);
}

void main_window::on_pushButton_4_clicked()
{
	response_for_clicked_button(consts::colors[3]);
}

void main_window::on_pushButton_5_clicked()
{
	response_for_clicked_button(consts::colors[4]);
}

void main_window::on_pushButton_6_clicked()
{
	response_for_clicked_button(consts::colors[5]);
}

void main_window::response_for_clicked_button(const char new_dominant_color)
{
	logger_h->log_debug(std::string({new_dominant_color}) + " button clicked.");
	iterate_turns_counter();
	palette->set_dominant_color(new_dominant_color);
}

void main_window::iterate_turns_counter()
{
	ui->label->setText(QString::number(++turns_counter));
}

void main_window::announce_victory()
{
	QMessageBox msgBox;
	QString message = "Congratulation! You've just won!";
	msgBox.information(this,"Victory!",message, QMessageBox::Ok);
}
