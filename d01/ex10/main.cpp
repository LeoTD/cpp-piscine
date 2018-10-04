#include <iostream>
#include <fstream>
#include <sstream>

int			main(int ac, char ** av) {
	if (ac == 1) {
		std::string		buf;
		while (!std::cin.eof()) {
			std::getline(std::cin, buf);
			std::cout << buf << std::endl;
			//std::cout << std::cin.rdbuf();
		}
		return 0;
	} else {
		for (int i = 1; i < ac; i++) {
			std::string			fname(av[i]);
			std::stringstream	ss;
			std::ifstream		ifs(fname);

			if (!ifs.is_open()) {
				std::cout << "cat 'o nine tails: " << fname << ": No such file or directory" << std::endl;
				continue ;
			}

			ss << ifs.rdbuf();
			ifs.close();

			std::cout << ss.str();
		}
	}
	return 0;
}
