#ifndef COMMON_CONSTS_H
#define COMMON_CONSTS_H

#include <string>
#include <vector>
#include <map>
#include <array>
#include <QColor>

namespace consts {
	extern const std::vector<char> colors;
	extern const int palette_size;
	extern const std::map<char, QColor> char_to_rgb_color_map;
} //namespace consts

#endif // COMMON_CONSTS_H
