#ifndef MODEL_H
#define MODEL_H

#include <boost/shared_ptr.hpp>
#include <vector>
#include "gen_main_window.h"

typedef boost::shared_ptr<gen_main_window> gen_main_window_t;

class model
{
public:
    model();
    ~model();

    void attach(gen_main_window_t obs);
    void detach(gen_main_window_t obs);
    void notify_change(int changed_element) const;

private:
    std::vector<gen_main_window_t> listen_observers;
};

#endif // MODEL_H
