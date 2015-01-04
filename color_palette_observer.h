#ifndef COLOR_PALETTE_OBSERVER_H
#define COLOR_PALETTE_OBSERVER_H

#include "model_observer.h"

class color_palette_observer : public model_observer
{
public:
    color_palette_observer();

    virtual void update(int changed_element);

};

#endif // COLOR_PALETTE_OBSERVER_H
