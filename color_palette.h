#ifndef COLOR_PALETTE_H
#define COLOR_PALETTE_H

#include "model.h"
#include <QObject>
#include "main_window.h"
#include "logger/logger.h"
#include <vector>
#include "common_consts.h"

typedef std::shared_ptr<class logger> logger_t;
typedef std::vector<std::vector<char>> matrix_t;

class color_palette : public QObject, public model
{
    Q_OBJECT

public:
	color_palette();

	int get_dominant_color();
	void set_dominant_color(int new_val);

	matrix_t get_current_palette();
private slots:
    void change_palette(int val);

private:
	int color_handler;
	logger_t logger_h;
	matrix_t palette;
	void initialize_palette();
	void assign_colors();
};

#endif // COLOR_PALETTE_H
