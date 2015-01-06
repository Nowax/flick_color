#include "logger/logger.h"
#include <iostream>
#include "common_consts.h"
#include <fstream>
#include <mutex>

logger::logger(std::string name) :
	my_name(name),
	time_controller_handler(time_controller_h(new time_controller()))
{
}

void logger::log_info(std::string msg)
{
#ifdef DEBUG_1
	print(msg, consts::log::info_detail);
#else
	msg.clear();
#endif
}

void logger::log_debug(std::string msg)
{
#ifdef DEBUG_2
	print(msg, consts::log::debug_detail);
#else
	msg.clear();
#endif
}

void logger::log_warning(std::string msg)
{
	print(msg, consts::log::warning_detail);
}

void logger::log_error(std::string msg)
{
	print(msg, consts::log::error_detail);
}

void logger::print(std::string msg, std::string log_type)
{
	std::string log_msg = time_controller_handler->get_current_time()
			+ log_type + std::string("\t")
			+ my_name + std::string(": ")
			+ msg + std::string("\n");

	std::cout << log_msg;
	save_log(log_msg);
}

void logger::save_log(std::string log_msg)
{
	std::mutex mtx;

	mtx.lock();
	std::ofstream log_file(	consts::log::log_name, std::ios_base::out | std::ios_base::app);
	log_file << log_msg;
}

