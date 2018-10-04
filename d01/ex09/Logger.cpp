#include <Logger.hpp>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

Logger::Logger(std::string const & fname): _file_name(fname) {}

void			Logger::logToConsole(std::string const & message) const {
	std::cout << makeLogEntry(message) << std::endl;
}

void			Logger::logToFile(std::string const & message) const {
	std::ofstream	ofs(_file_name, std::ios::app);
	ofs << makeLogEntry(message) << std::endl;
}

void			Logger::log(std::string const & dest, std::string const & message) const {
	std::string const		destinations[] = {
		"console",
		"file"
	};

	typedef void (Logger::*fptr)(std::string const &) const;
	fptr actions[] = {
		&Logger::logToConsole,
		&Logger::logToFile
	};

	for (unsigned int i = 0; i < (sizeof(destinations) / sizeof(destinations[0])); i++) {
		if (dest == destinations[i]) {
			(this->*(actions[i]))(message);
		}
	}

}

std::string		Logger::_getTimestamp(void) const {
	time_t					rawtime;
	struct tm				*ti;
	std::stringstream		stamp;

	time(&rawtime);
	ti = localtime(&rawtime);
	stamp << "[";
	stamp << ti->tm_year + 1900;
	stamp << std::setfill ('0') << std::setw (2);
	stamp << ti->tm_mon;
	stamp << std::setfill ('0') << std::setw (2);
	stamp << ti->tm_mday;
	stamp << "_";
	stamp << std::setfill ('0') << std::setw (2);
	stamp << ti->tm_hour;
	stamp << std::setfill ('0') << std::setw (2);
	stamp << ti->tm_min;
	stamp << std::setfill ('0') << std::setw (2);
	stamp << ti->tm_sec;
	stamp << "]";
	return stamp.str();
}

std::string		Logger::makeLogEntry(std::string const & message) const {
	std::string		entry(_getTimestamp());

	entry += " ";
	entry += message;
	return entry;
}
