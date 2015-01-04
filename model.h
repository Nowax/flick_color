#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <vector>
#include "gen_main_window.h"
#include "model_observer.h"

//typedef std::shared_ptr<gen_main_window> gen_main_window_t;
typedef std::shared_ptr<model_observer> model_observer_t;

class model
{
public:
    model();
    ~model();

    void attach(model_observer_t obs);
    void detach(model_observer_t obs);
    void notify_change(int changed_element) const;

private:
    std::vector<model_observer_t> listen_observers;
};

#endif // MODEL_H
