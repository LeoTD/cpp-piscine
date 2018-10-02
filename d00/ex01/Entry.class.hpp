#ifndef ENTRY_CLASS_HPP
# define ENTRY_CLASS_HPP

# include <string>

class Entry {
public:
	Entry();
	~Entry();

	std::string		_first_name;
	std::string		_last_name;
	std::string		_nickname;
	std::string		_login;
	std::string		_postal_addr;
	std::string		_email;
	std::string		_phone;
	std::string		_birthday;
	std::string		_favorite_meal;
	std::string		_underwear_color;
	std::string		_darkest_secret;
};

#endif