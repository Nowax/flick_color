#ifndef MODEL_OBSERVER_H
#define MODEL_OBSERVER_H

class model_observer
{
public:
    model_observer();

    virtual void update(int changed_element) = 0;
};

#endif // MODEL_OBSERVER_H
