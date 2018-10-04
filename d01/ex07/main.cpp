#include <iostream>
#include <fstream>
#include <sstream>

void		usage(void) {
	std::cout << "Usage: ./replace [file name] [find] [replace]\n\nex: ./replace Makefile NAME cat" <<std::endl;
}

int			main(int ac, char ** av) {
	if (ac != 4) {
		usage();
		return 0;
	}

	std::string			fname(av[1]);
	std::string			find(av[2]);
	std::string			replace(av[3]);

	std::streampos		size;
	std::string			buf;
	std::ifstream		ifs(fname);
	std::stringstream	ss;

	ss << ifs.rdbuf();
	buf = ss.str();
	ifs.close();

	int					found_index;

	while ( (unsigned long)(found_index = buf.find(find)) != std::string::npos ) {
		buf.replace(found_index, find.length(), replace);
	}

	fname += ".replace";
	std::ofstream		ofs(fname);

	ofs << buf << std::endl;

	return 0;
}
