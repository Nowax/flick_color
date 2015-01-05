#include "model.h"
#include <algorithm>

model::model() :
	self_handler(this)
{
}

model::~model()
{
    listen_observers.clear();
}

void model::attach(std::shared_ptr<model_observer> obs)
{
    listen_observers.push_back(obs);
}

void model::detach(std::shared_ptr<class model_observer> obs)
{
    auto it = std::find(listen_observers.begin(),listen_observers.end(), obs);
    if (it != listen_observers.end()) {
        listen_observers.erase(it);
    }
}

void model::notify_change() const
{
	for (const auto& observer : listen_observers) {
        if (observer) {
			observer->update(self_handler);
        }
    }
}
