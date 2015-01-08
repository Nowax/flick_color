#include "common_consts.h"
#include <boost/assign.hpp>
#include <array>

namespace consts {
	const std::vector<char> colors = boost::assign::list_of
			('B')('G')('R')('Y')('O')('P');
	const std::map<char, QColor> char_to_rgb_color_map = boost::assign::map_list_of
			(colors[0], QColor({0, 0, 255}))
			(colors[1], QColor({0, 255, 0}))
			(colors[2], QColor({255, 0, 0}))
			(colors[3], QColor({255, 255, 0}))
			(colors[4], QColor({255, 127, 0}))
			(colors[5], QColor({205, 41, 144}));
	const int palette_size = 15;
} // namespace consts
