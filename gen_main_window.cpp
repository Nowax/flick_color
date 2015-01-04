#include "gen_main_window.h"
#include "ui_gen_main_window.h"
#include <QDebug>

gen_main_window::gen_main_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gen_main_window)
{
    ui->setupUi(this);
}

gen_main_window::~gen_main_window()
{
    delete ui;
}

void gen_main_window::update(int changed_element)
{
    qDebug() << changed_element;
    ui->label->text(QString::number(changed_element));
}

void gen_main_window::on_spinBox_valueChanged(int arg1)
{
    emit refresh_palette(arg1);
}
