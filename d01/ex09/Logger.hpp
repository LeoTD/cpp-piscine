#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>

class Logger {
public:
	Logger(std::string const & fname = std::string("logfile.log"));

	void			logToConsole(std::string const &) const;
	void			logToFile(std::string const &) const;
	void			log(std::string const &, std::string const &) const;

	std::string		makeLogEntry(std::string const &) const;

private:
	std::string const		_file_name;

	std::string		_getTimestamp(void) const;
};

#endif
