#include "Book.class.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

Book::Book() {
	//_entry = new Entry[8]();
	_nbr_entries = 0;
	return ;
}

Book::~Book() {
	//delete[] _entry;
	return ;
}

void		Book::add_entry() {
	if (_nbr_entries > 7) {
		std::cout << "The PC Box is full!" << std::endl;
	}
	else {
		std::string		buf;
		Entry *x = &this->_entry[_nbr_entries++];
		std::cout << "First name?: ";
		std::getline(std::cin, x->_first_name);
		std::cout << "Last_name?: ";
		std::getline(std::cin, x->_last_name);
		std::cout << "Nickname?: ";
		std::getline(std::cin, x->_nickname);
		std::cout << "Login?: ";
		std::getline(std::cin, x->_login);
		std::cout << "Postal address?: ";
		std::getline(std::cin, x->_postal_addr);
		std::cout << "Email?: ";
		std::getline(std::cin, x->_email);
		std::cout << "Phone?: ";
		std::getline(std::cin, x->_phone);
		std::cout << "Birthday?: ";
		std::getline(std::cin, x->_birthday);
		std::cout << "Favorite Meal?: ";
		std::getline(std::cin, x->_favorite_meal);
		std::cout << "Underwear Color?: ";
		std::getline(std::cin, x->_underwear_color);
		std::cout << "Darkest Secret?: ";
		std::getline(std::cin, x->_darkest_secret);
	}
}

void		Book::search() {
	std::string		buf;
	int				idx;

	print_entries();
	while (1) {
		std::cout << "Choose your Pokemon! (Enter index)> ";
		std::getline(std::cin, buf);
		if (buf[0] >= '0' && buf[0] <= '7' && buf[1] == '\0') {
			idx = buf[0] - '0';
			if (idx < _nbr_entries) {
				__printf_full_entry(idx);
				break ;
			}
		}
		std::cout << "Pika~~???" << std::endl;
	}
}

void		__print_one_entry(std::string& str) {
	if (str.length() > 10) {
		std::cout << std::setfill (' ') << std::setw (9) << str.substr(0, 9) << ".";
	} else {
		std::cout << std::setfill (' ') << std::setw (10) << str.substr(0, 10);
	}
}

void		Book::print_entries() {
	if (_nbr_entries == 0) {
		std::cout << "The PC Box is empty!" << std::endl;
	} else {
		for (int i = 0; i < _nbr_entries; i++) {
			std::cout << std::setfill (' ') << std::setw (10) << i << " | ";
			__print_one_entry(_entry[i]._first_name);
			std::cout << " | ";
			__print_one_entry(_entry[i]._last_name);
			std::cout << " | ";
			__print_one_entry(_entry[i]._nickname);
			std::cout << std::endl;
		}
	}
}

void		Book::__printf_full_entry(int i) {
	if (i < _nbr_entries) {
		std::cout << "First Name: " << _entry[i]._first_name << std::endl;
		std::cout << "Last Name: " << _entry[i]._last_name << std::endl;
		std::cout << "Nickname: " << _entry[i]._nickname << std::endl;
		std::cout << "Login: " << _entry[i]._login << std::endl;
		std::cout << "Postal Address: " << _entry[i]._postal_addr << std::endl;
		std::cout << "Email: " << _entry[i]._email << std::endl;
		std::cout << "Phone: " << _entry[i]._phone << std::endl;
		std::cout << "Birthday: " << _entry[i]._birthday << std::endl;
		std::cout << "Favorite Meal: " << _entry[i]._favorite_meal << std::endl;
		std::cout << "Underwear Color: " << _entry[i]._underwear_color << std::endl;
		std::cout << "Darkest Secret: " << _entry[i]._darkest_secret << std::endl;
	}
}