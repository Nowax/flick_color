#include "model.h"

model::model()
{
}

model::~model()
{
    listen_observers.clear();
}

void model::attach(gen_main_window_t obs)
{
    listen_observers.push_back(obs);
}

void model::detach(gen_main_window_t obs)
{
    auto it = std::find(listen_observers.begin(),listen_observers.end(), obs);
    if (it != listen_observers.end()) {
        listen_observers.erase(it);
    }
}

void model::notify_change(int changed_element) const
{
    for (const auto& observer : listen_observers) {
        if (observer) {
            observer->update(changed_element);
        }
    }
}
