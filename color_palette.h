#ifndef COLOR_PALETTE_H
#define COLOR_PALETTE_H

#include "gen_main_window.h"
#include "model.h"
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<gen_main_window> gen_main_window_t;

class color_palette : public model, public QObject
{
public:
    Q_OBJECT
    color_palette(gen_main_window_t mw);

private slots:
    void change_palette(int val);

private:
    int palette;
};

#endif // COLOR_PALETTE_H
