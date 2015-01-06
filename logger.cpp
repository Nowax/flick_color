#include "logger.h"
#include <iostream>
#include "common_consts.h"
#include <fstream>

logger::logger(std::string name) :
	my_name(name),
	time_controller_handler(time_controller_h(new time_controller()))
{
}

void logger::log_info(std::string msg)
{
#ifdef DEBUG_1
	std::string log_type = consts::log::info_detail;
	print(msg, log_type);
#else
	msg.clear();
#endif
}

void logger::log_debug(std::string msg)
{
#ifdef DEBUG_2
	std::string log_type = consts::log::debug_detail;
	print(msg, log_type);
#else
	msg.clear();
#endif
}

void logger::log_warning(std::string msg)
{
	std::string log_type = consts::log::warning_detail;
	print(msg, log_type);
}

void logger::log_error(std::string msg)
{
	std::string log_type = consts::log::error_detail;
	print(msg, log_type);
}

void logger::print(std::string msg, std::string log_type)
{
	std::string time = time_controller_handler->get_current_time();

	std::string log_msg = time + log_type + std::string("\t")
			+ my_name + std::string(": ") + msg + std::string("\n");
	std::cout << log_msg;
	save_log(log_msg);
}

void logger::save_log(std::string log_msg)
{
	std::ofstream log_file(	consts::log::log_name, std::ios_base::out | std::ios_base::app);
	log_file << log_msg;
}

