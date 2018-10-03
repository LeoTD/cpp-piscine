#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
public:
	Weapon(std::string);
	~Weapon();

	std::string const &		getType() const;
	void					setType(std::string);

private:
	std::string				_type;
};

#endif