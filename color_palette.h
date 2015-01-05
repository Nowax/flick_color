#ifndef COLOR_PALETTE_H
#define COLOR_PALETTE_H

#include "model.h"
#include <QObject>
#include "main_window.h"

class color_palette : public QObject, public model
{
    Q_OBJECT

public:
	color_palette(std::shared_ptr<class main_window> main_window);

	int get_dominant_color();
	void set_dominant_color(int new_val);

private slots:
    void change_palette(int val);

private:
	int color_handler;
};

#endif // COLOR_PALETTE_H
