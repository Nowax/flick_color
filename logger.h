#ifndef LOGGER_H
#define LOGGER_H

#include "time_controller.h"
#include <string>
#include <fstream>
#include <ctime>
#include <QtCore/QDebug>
#include <string>
#include <memory>
#include <iomanip>

typedef std::shared_ptr<class time_controller> time_controller_h;

class logger
{
public:
	logger(std::string name);

	void log_info(std::string msg);
	void log_debug(std::string msg);
	void log_warning(std::string msg);
	void log_error(std::string msg);

private:
	std::string my_name;
	std::string log;
	std::ofstream fileToSaveData;
	time_controller_h time_controller_handler;

	void print(std::string msg, std::string log_type);
	std::string create_file_name();
	void save_log();

};

#endif // LOGGER_H
