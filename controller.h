#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"
#include "view.h"

typedef std::shared_ptr<class model> model_t;
typedef std::shared_ptr<class view> view_t;

class controller
{
public:
	controller();

	virtual void subscribe_model(model_t new_model) = 0;
	virtual void subscribe_view(view_t new_view) = 0;

protected:
	model_t my_model;
	view_t my_view;
};

#endif // CONTROLLER_H
