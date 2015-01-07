#include "common_consts.h"
#include <boost/assign.hpp>

namespace consts {
namespace log {
	const std::string log_name = "SYSLOG.log";
	const std::string error_detail = "[ERR] ";
	const std::string warning_detail = "[WRN] ";
	const std::string info_detail = "[INFO] ";
	const std::string debug_detail = "[DBG] ";	
} // namespace log

	const std::vector<char> colors = boost::assign::list_of
			('#')('$')('?')('@')('X')('|');
	const int palette_size = 15;
} // namespace consts
