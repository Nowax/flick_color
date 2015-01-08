#ifndef MODEL_OBSERVER_H
#define MODEL_OBSERVER_H

#include "model.h"
#include <memory>

class model_observer
{
public:
	model_observer();
	virtual ~model_observer();
	virtual void update(std::shared_ptr<class model>) = 0;

protected:

};

#endif // MODEL_OBSERVER_H
