#include <Logger.hpp>
#include <iostream>

int		main(void) {
	Logger		lg;//("Insert file name here");

	std::cout << lg.makeLogEntry("Hello World") << std::endl;
	lg.logToConsole("to console");
	lg.logToFile("to file");
	lg.log("file", "to file again");
	lg.log("console", "to console again");
	lg.log("bad destination", "this shouldn't print");
	return 0;
}
