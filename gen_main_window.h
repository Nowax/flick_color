#ifndef GEN_MAIN_WINDOW_H
#define GEN_MAIN_WINDOW_H

#include <QMainWindow>
#include "model_observer.h"
#include "color_palette.h"

namespace Ui {
class gen_main_window;
}

class gen_main_window : public QMainWindow, public model_observer
{
    Q_OBJECT

public:
    explicit gen_main_window(QWidget *parent = 0);
    void update(int changed_element);
    ~gen_main_window();

signals:
    void refresh_palette(int val);

private slots:
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::gen_main_window *ui;
};

#endif // GEN_MAIN_WINDOW_H
