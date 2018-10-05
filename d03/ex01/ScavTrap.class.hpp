#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

# include <iostream>
# include <string>

class ScavTrap {
public:
	ScavTrap(std::string);
	ScavTrap(ScavTrap const &);
	ScavTrap &operator=(ScavTrap const &);
	~ScavTrap();

	void			rangedAttack(std::string const &) const;
	void			meleeAttack(std::string const &) const;
	void			takeDamage(unsigned int);
	void			beRepaired(unsigned int);
	void			displayStatus(void) const;
	void			challengeNewcomer(std::string const &);
	std::string		getName(void) const;

	unsigned int	_get_hp(void) const;
	void			_set_hp(unsigned int);
	unsigned int	_get_MAX_HP(void) const;
	void			_set_MAX_HP(unsigned int);
	unsigned int	_get_energy(void) const;
	void			_set_energy(unsigned int);
	unsigned int	_get_MAX_ENERGY(void) const;
	void			_set_MAX_ENERGY(unsigned int);
	unsigned int	_get_level(void) const;
	void			_set_level(unsigned int);
	std::string		_get_name(void) const;
	void			_set_name(std::string const &);
	unsigned int	_get_melee_dmg(void) const;
	void			_set_melee_dmg(unsigned int);
	unsigned int	_get_ranged_dmg(void) const;
	void			_set_ranged_dmg(unsigned int);
	unsigned int	_get_armor(void) const;
	void			_set_armor(unsigned int);

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

std::ostream &		operator<<(std::ostream &, ScavTrap const &);

#endif
