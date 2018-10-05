#include "ScavTrap.class.hpp"

// --------------------------------------------------------- //
// ---- Constructors									---- //
// --------------------------------------------------------- //

ScavTrap::ScavTrap(std::string name)
	:	_hp(100),
		_MAX_HP(100),
		_energy(50),
		_MAX_ENERGY(50),
		_level(1),
		_name(name),
		_melee_dmg(20),
		_ranged_dmg(15),
		_armor(3)
{

	return ;
}

ScavTrap::ScavTrap(ScavTrap const & that) {
	*this = that;
	return ;
}

ScavTrap::~ScavTrap() {

	return ;
}

// --------------------------------------------------------- //
// ---- Operators										---- //
// --------------------------------------------------------- //

ScavTrap &	ScavTrap::operator=(ScavTrap const & that) {
	if (this != &that) {
		_set_hp(that._get_hp());
		_set_MAX_HP(that._get_MAX_HP());
		_set_energy(that._get_energy());
		_set_MAX_ENERGY(that._get_MAX_ENERGY());
		_set_level(that._get_level());
		_set_name(that._get_name());
		_set_melee_dmg(that._get_melee_dmg());
		_set_ranged_dmg(that._get_ranged_dmg());
		_set_armor(that._get_armor());	
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & os, ScavTrap const & that) {
	os << that.getName();
	return os;
}

// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //

std::string			ScavTrap::getName(void) const {
	return _name;
}

void				ScavTrap::displayStatus() const {
	std::cout << "<SCAV-TP; " << _name << "> ";
	std::cout << "HP: ";
	if (_hp == 0) {
		std::cout << "\033[91m\033[1m";
	}
	std::cout << _hp << "/" << _MAX_HP << " \033[0m";
	std::cout << "ENERGY: " << _energy << "/" << _MAX_ENERGY << " ";
	std::cout << "ARMOR: " << _armor << " ";
	std::cout << std::endl;
}

void				ScavTrap::meleeAttack(std::string const & tar) const {
	unsigned int		r = arc4random() % 3;

	std::cout << "<SCAV-TP; " << _name << "> ";
	switch(r) {
		case 0:
			std::cout << "Hyaah!" << std::endl;
			break ;
		case 1:
			std::cout << "Tremble before my might!" << std::endl;
			break ;
		case 2:
			std::cout << "Die HEATHEN." << std::endl;
			break ;
	}
	std::cout << "<Headbutt> deals " << _melee_dmg << " damage";
	std::cout << " to " << tar << std::endl;
	displayStatus();
	return ;
}

void				ScavTrap::rangedAttack(std::string const & tar) const {
	unsigned int		r = arc4random() % 3;

	std::cout << "<SCAV-TP; " << _name << "> ";
	switch(r) {
		case 0:
			std::cout << "Is that what people look like inside?" << std::endl;
			break ;
		case 1:
			std::cout << "AAAAAAAHHHH!!~" << std::endl;
			break ;
		case 2:
			std::cout << "You call yourself a badass?" << std::endl;
			break ;
	}
	std::cout << "<Minigun> deals " << _ranged_dmg << " damage";
	std::cout << " to " << tar << std::endl;
	displayStatus();
	return ;
}

void				ScavTrap::takeDamage(unsigned int n) {
	if (_hp == 0) {
		std::cout << "<SCAV-TP; " << _name << "> ";
		std::cout << "* angry dead robot noises *" << std::endl;
		std::cout << "<SCAV-TP; " << _name << "> ";
		std::cout << "takes " << n << " overkill damage" << std::endl;
		return ;
	}
	if (n >= (_hp + _armor)) {
		_hp = 0;
	} else {
		_hp -= (n - _armor);
	}
	if (_hp > 0) {
		std::cout << "<SCAV-TP; " << _name << "> ";
		std::cout << "You'll pay for that!" << std::endl;
		std::cout << "<SCAV-TP; " << _name << "> ";
		std::cout << "takes " << n << " damage" << std::endl;
	} else {
		std::cout << "<SCAV-TP; " << _name << "> ";
		std::cout << "AaAaHHH!!!111!1brrrzzzttt..." << std::endl;
		std::cout << "<SCAV-TP; " << _name << "> ";
		std::cout << "takes " << n << " damage" << std::endl;
	}
	displayStatus();
}

void				ScavTrap::beRepaired(unsigned int n) {
	if ((_hp + n) > _MAX_HP) {
		_hp = _MAX_HP;
	} else {
		_hp += n;
	}
	if (_hp == _MAX_HP) {
		std::cout << "<SCAV-TP; " << _name << "> ";
		std::cout << "I'm UNSTOPPABLE! HAhahaha!" << std::endl;
		std::cout << "<SCAV-TP; " << _name << "> ";
		std::cout << "heals " << n << " hit-points" << std::endl;
	} else if (_hp == n) {
		std::cout << "<SCAV-TP; " << _name << "> ";
		std::cout << "* Windows Startup Noise *" << std::endl;
		std::cout << "<SCAV-TP; " << _name << "> ";
		std::cout << "heals " << n << " hit-points" << std::endl;
	} else {
		std::cout << "<SCAV-TP; " << _name << "> ";
		std::cout << "Yes! More POWER." << std::endl;
		std::cout << "<SCAV-TP; " << _name << "> ";
		std::cout << "heals " << n << " hit-points" << std::endl;
	}
	displayStatus();
}

void			ScavTrap::challengeNewcomer(std::string const & tar) {
	unsigned int	r = arc4random() % 5;

	std::cout << "<SCAV-TP; " << _name << "> ";
	std::cout << "Hey " << tar << "! ";
	switch(r) {
		case 0:
			std::cout << "You versus me! Me versus you! Either way!" << std::endl;
			break ;
		case 1:
			std::cout << "I will prove to you my robotic superiority!" << std::endl;
			break ;
		case 2:
			std::cout << "Man versus machine! Very tiny streamlined machine!" << std::endl;
			break ;
		case 3:
			std::cout << "Care to have a friendly duel?" << std::endl;
			break ;
		case 4:
			std::cout << "Dance battle! Or, you know... regular battle." << std::endl;
			break ;
	}
}

// --------------------------------------------------------- //
// ---- Getters and Setters								---- //
// --------------------------------------------------------- //

unsigned int	ScavTrap::_get_hp(void) const {
	return _hp;
}

void			ScavTrap::_set_hp(unsigned int nval) {
	_hp = nval;
}

unsigned int	ScavTrap::_get_MAX_HP(void) const {
	return _MAX_HP;
}

void			ScavTrap::_set_MAX_HP(unsigned int nval) {
	_MAX_HP = nval;
}

unsigned int	ScavTrap::_get_energy(void) const {
	return _energy;
}

void			ScavTrap::_set_energy(unsigned int nval) {
	_energy = nval;
}

unsigned int	ScavTrap::_get_MAX_ENERGY(void) const {
	return _MAX_ENERGY;
}

void			ScavTrap::_set_MAX_ENERGY(unsigned int nval) {
	_MAX_ENERGY = nval;
}

unsigned int	ScavTrap::_get_level(void) const {
	return _level;
}

void			ScavTrap::_set_level(unsigned int nval) {
	_level = nval;
}

std::string		ScavTrap::_get_name(void) const {
	return _name;
}

void			ScavTrap::_set_name(std::string const & nval) {
	_name = nval;
}

unsigned int	ScavTrap::_get_melee_dmg(void) const {
	return _melee_dmg;
}

void			ScavTrap::_set_melee_dmg(unsigned int nval) {
	_melee_dmg = nval;
}

unsigned int	ScavTrap::_get_ranged_dmg(void) const {
	return _ranged_dmg;
}

void			ScavTrap::_set_ranged_dmg(unsigned int nval) {
	_ranged_dmg = nval;
}

unsigned int	ScavTrap::_get_armor(void) const {
	return _armor;
}

void			ScavTrap::_set_armor(unsigned int nval) {
	_armor = nval;
}
