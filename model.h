#ifndef MODEL_H
#define MODEL_H

#include "model_observer.h"
#include <memory>
#include <list>

class model
{
public:
    model();
    ~model();

	void attach(std::shared_ptr<class model_observer> obs);
	void detach(std::shared_ptr<class model_observer> obs);
	void notify_change() const;

private:
	std::list<std::shared_ptr<class model_observer>> listen_observers;
	std::shared_ptr<class model> self_handler;
};

#endif // MODEL_H
