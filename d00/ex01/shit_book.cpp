#include <Book.class.hpp>
#include <Entry.class.hpp>
#include <iostream>
#include <string>

void	to_upper(std::string& str)
{
	for (std::string::iterator i = str.begin(); i != str.end(); i++) {
		if (*i >= 'a' && *i <= 'z') {
			*i += ('A' - 'a');
		}
	}
}

int		main(void) {
	std::string		buf;
	Book			b;

	while (1) {
		std::cout << "-ϞϞ(๑⚈ ․̫ ⚈๑)∩> ";
		std::getline(std::cin, buf);
		to_upper(buf);
		if (buf == "ADD") {
			b.add_entry();
		} else if (buf == "SEARCH") {
			b.search();
		} else if (buf == "EXIT") {
			break ;
		}
	}
}