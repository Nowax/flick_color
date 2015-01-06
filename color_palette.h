#ifndef COLOR_PALETTE_H
#define COLOR_PALETTE_H

#include "model.h"
#include <QObject>
#include "main_window.h"
#include "logger.h"

typedef std::shared_ptr<class logger> logger_t;

class color_palette : public QObject, public model
{
    Q_OBJECT

public:
	color_palette();

	int get_dominant_color();
	void set_dominant_color(int new_val);

private slots:
    void change_palette(int val);

private:
	int color_handler;
	logger_t logger_h;
};

#endif // COLOR_PALETTE_H
