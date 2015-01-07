#ifndef COMMON_CONSTS_H
#define COMMON_CONSTS_H

#include <string>
#include <vector>
#include <map>
#include <array>
#include <QColor>

namespace consts {
namespace log{
	extern const std::string log_name;
	extern const std::string error_detail;
	extern const std::string warning_detail;
	extern const std::string info_detail;
	extern const std::string debug_detail;
} //naespace log
	extern const std::vector<char> colors;
	extern const int palette_size;
	extern const std::map<char, QColor> char_to_rgb_color_map;
} //namespace consts

#endif // COMMON_CONSTS_H
