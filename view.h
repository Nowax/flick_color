#ifndef VIEW_H
#define VIEW_H

#include <vector>

typedef std::vector<std::vector<std::pair<char, bool>>> matrix_t;

class view
{
public:
	view();

	virtual void update(matrix_t new_palette) = 0;
	virtual void announce_victory() = 0;
};

#endif // VIEW_H
