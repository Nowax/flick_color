#define _POSIX_C_SOURCE 200809L
#include "time_controller.h"
#include <QDebug>
#include <inttypes.h>
#include <math.h>
#include <sstream>

time_controller::time_controller()
{
}

std::string time_controller::get_current_time()
{
	struct tm *local_time;
	struct timespec spec;
	std::stringstream miliseconds;

	clock_gettime(CLOCK_REALTIME, &spec);

	local_time = localtime (&spec.tv_sec);
	miliseconds << round(spec.tv_nsec / 1.0e3);
	std::string ms_str = ":" + miliseconds.str();

	std::string string_time = asctime(local_time);
	string_time.pop_back();
	string_time.insert(string_time.size()-5, ms_str);
	string_time.push_back('\t');

	return string_time;
}
