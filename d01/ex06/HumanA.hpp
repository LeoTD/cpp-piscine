#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <Weapon.hpp>
# include <string>

class HumanA {
public:
	HumanA(std::string, Weapon&);
	~HumanA();

	void		attack() const;
	void		setWeapon(Weapon);

private:
	Weapon &	_weapon;
	std::string	_name;
};

#endif