#ifndef COLOR_PALETTE_H
#define COLOR_PALETTE_H

#include "model.h"
#include <QObject>
#include "main_window.h"
#include "src/log/logger.h"
#include <vector>
#include "common_consts.h"

typedef std::shared_ptr<class logger> logger_t;
typedef std::vector<std::vector<std::pair<char, bool>>> matrix_t;

class color_palette : public QObject, public model
{
    Q_OBJECT

public:
	color_palette();

	int get_dominant_color();
	void set_dominant_color(char new_val);

	matrix_t get_current_palette();
private slots:
	void change_palette(char new_dominant);

private:
	char color_handler;
	logger_t logger_h;
	matrix_t palette;
	void initialize_palette();
	void assign_colors();
	void refresh_cells_chain_state();
	void apply_new_dominant_color(char new_dominant);
	bool is_connected_to_chain(std::pair<int, int> index);
	std::vector<int> define_offset(std::pair<int, int> index);
};

#endif // COLOR_PALETTE_H
