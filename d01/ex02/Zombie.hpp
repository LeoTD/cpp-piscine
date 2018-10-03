#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
public:

	Zombie();
	Zombie(std::string name, std::string type);
	~Zombie();

	std::string		_type;
	std::string		_name;

	void			announce(void);
};

#endif