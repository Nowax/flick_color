#include "logger.h"
#include <iostream>
#include <map>
#include <time.h>

namespace consts {
namespace save {
	const std::string separator = ", ";
	const std::string newLine = "\n";
	const std::string fileNameSuffix = ".csv";
	const std::string fileNamePrefix = "pomiar_";
	const unsigned int systemStartYear = 1990;
	const unsigned int januaryStartsAt1 = 1;
	namespace message {
		const QString openingFileError = "Open file error!";
	} //namespace message
} // namespace save
}


logger::logger(std::string name) :
	my_name(name),
	time_controller_handler(time_controller_h(new time_controller()))
{
}

void logger::log_info(std::string msg)
{
#ifdef DEBUG_1
	std::string log_type = "[INFO] ";
	print(msg, log_type);
#else
	msg.clear();
#endif
}

void logger::log_debug(std::string msg)
{
#ifdef DEBUG_2
	std::string log_type = "[DBG] ";
	print(msg, log_type);
#else
	msg.clear();
#endif
}

void logger::log_warning(std::string msg)
{
	std::string log_type = "[WRN] ";
	print(msg, log_type);
}

void logger::log_error(std::string msg)
{
	std::string log_type = "[ERR] ";
	print(msg, log_type);
}

void logger::print(std::string msg, std::string log_type)
{
	std::string time = time_controller_handler->get_current_time();

	std::string log_msg = time + log_type + my_name + std::string(": ") + msg + std::string("\n");
	log += log_msg;
	std::cout << log_msg;
}


//void logger::save_log()
//{
//	std::string fileName = create_file_name();;

//	fileToSaveData.open( fileName , std::ios::out, std::ios::trunc );
//	fileToSaveData << log;
//	fileToSaveData.close();
//}

//std::string logger::create_file_name()
//{
//	time_t rawtime;
//	struct tm timeinfo;
//	time(&rawtime);
//	localtime_s(&timeinfo,&rawtime);

//	char date[20];
//	sprintf_s(date,20,"%04d-%02d-%02d_%02d-%02d-%02d",
//			(consts::save::systemStartYear + timeinfo.tm_year),
//			(consts::save::januaryStartsAt1 + timeinfo.tm_mon),
//			timeinfo.tm_mday,
//			timeinfo.tm_hour,
//			timeinfo.tm_min,
//			timeinfo.tm_sec);
//	std::string stringDate(date), fileName;
//	fileName = "SYSLOG_" +
//			   stringDate;

//	return fileName;
//}
