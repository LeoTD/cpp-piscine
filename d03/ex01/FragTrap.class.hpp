#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

# include <iostream>
# include <string>

class FragTrap {
public:
	FragTrap(std::string);
	FragTrap(FragTrap const &);
	FragTrap &operator=(FragTrap const &);
	~FragTrap();

	void			rangedAttack(std::string const &) const;
	void			meleeAttack(std::string const &) const;
	void			takeDamage(unsigned int);
	void			beRepaired(unsigned int);
	void			displayStatus(void) const;
	void			vaulthunter_dot_exe(std::string const &);

private:
	unsigned int	_hp;
	unsigned int	_MAX_HP;
	unsigned int	_energy;
	unsigned int	_MAX_ENERGY;
	unsigned int	_level;
	std::string		_name;
	unsigned int	_melee_dmg;
	unsigned int	_ranged_dmg;
	unsigned int	_armor;
	
};

std::ostream &		operator<<(std::ostream &, FragTrap const &);

#endif
