#include "FragTrap.class.hpp"

// --------------------------------------------------------- //
// ---- Constructors									---- //
// --------------------------------------------------------- //

FragTrap::FragTrap(std::string name)
	:	_hp(100),
		_MAX_HP(100),
		_energy(100),
		_MAX_ENERGY(100),
		_level(1),
		_name(name),
		_melee_dmg(30),
		_ranged_dmg(20),
		_armor(5)
{

	return ;
}

FragTrap::FragTrap(FragTrap const & that) {
	*this = that;
	return ;
}

FragTrap::~FragTrap() {

	return ;
}

// --------------------------------------------------------- //
// ---- Operators										---- //
// --------------------------------------------------------- //

FragTrap &	FragTrap::operator=(FragTrap const & that) {
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

std::ostream &	operator<<(std::ostream & os, FragTrap const & that) {
	os << that.getName();
	return os;
}

// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //

std::string			FragTrap::getName(void) const {
	return _name;
}

void				FragTrap::displayStatus() const {
	std::cout << "<FR4G-TP; " << _name << "> ";
	std::cout << "HP: ";
	if (_hp == 0) {
		std::cout << "\033[91m\033[1m";
	}
	std::cout << _hp << "/" << _MAX_HP << " \033[0m";
	std::cout << "ENERGY: " << _energy << "/" << _MAX_ENERGY << " ";
	std::cout << "ARMOR: " << _armor << " ";
	std::cout << std::endl;
}

void				FragTrap::meleeAttack(std::string const & tar) const {
	unsigned int		r = arc4random() % 3;

	std::cout << "<FR4G-TP; " << _name << "> ";
	switch(r) {
		case 0:
			std::cout << "Take THAT!" << std::endl;
			break ;
		case 1:
			std::cout << "There is no way this ends badly!" << std::endl;
			break ;
		case 2:
			std::cout << "WOW! I hit 'em!" << std::endl;
			break ;
	}
	std::cout << "<Headbutt> deals " << _melee_dmg << " damage";
	std::cout << " to " << tar << std::endl;
	displayStatus();
	return ;
}

void				FragTrap::rangedAttack(std::string const & tar) const {
	unsigned int		r = arc4random() % 4;

	std::cout << "<FR4G-TP; " << _name << "> ";
	switch(r) {
		case 0:
			std::cout << "250 shots per second, ONE KILL!" << std::endl;
			break ;
		case 1:
			std::cout << "Let's get this party started!" << std::endl;
			break ;
		case 2:
			std::cout << "Flesh fireworks!" << std::endl;
			break ;
		case 3:
			std::cout << "Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa!" << std::endl;
			break ;
	}
	std::cout << "<Minigun> deals " << _ranged_dmg << " damage";
	std::cout << " to " << tar << std::endl;
	displayStatus();
	return ;
}

void				FragTrap::takeDamage(unsigned int n) {
	if (_hp == 0) {
		std::cout << "<FR4G-TP; " << _name << "> ";
		std::cout << "* angry dead robot noises *" << std::endl;
		std::cout << "<FR4G-TP; " << _name << "> ";
		std::cout << "takes " << n << " overkill damage" << std::endl;
		return ;
	}
	if (n >= (_hp + _armor)) {
		_hp = 0;
	} else {
		_hp -= (n - _armor);
	}
	if (_hp > 0) {
		std::cout << "<FR4G-TP; " << _name << "> ";
		std::cout << "Ouch! Watch it! This is a vintage chasis!" << std::endl;
		std::cout << "<FR4G-TP; " << _name << "> ";
		std::cout << "takes " << n << " damage" << std::endl;
	} else {
		std::cout << "<FR4G-TP; " << _name << "> ";
		std::cout << "AaAaHHH!!!111!1brrrzzzttt..." << std::endl;
		std::cout << "<FR4G-TP; " << _name << "> ";
		std::cout << "takes " << n << " damage" << std::endl;
	}
	displayStatus();
}

void				FragTrap::beRepaired(unsigned int n) {
	if ((_hp + n) > _MAX_HP) {
		_hp = _MAX_HP;
	} else {
		_hp += n;
	}
	if (_hp == _MAX_HP) {
		std::cout << "<FR4G-TP; " << _name << "> ";
		std::cout << "I'm UNSTOPPABLE! HAhahaha!" << std::endl;
		std::cout << "<FR4G-TP; " << _name << "> ";
		std::cout << "heals " << n << " hit-points" << std::endl;
	} else if (_hp == n) {
		std::cout << "<FR4G-TP; " << _name << "> ";
		std::cout << "* Windows Startup Noise *" << std::endl;
		std::cout << "<FR4G-TP; " << _name << "> ";
		std::cout << "heals " << n << " hit-points" << std::endl;
	} else {
		std::cout << "<FR4G-TP; " << _name << "> ";
		std::cout << "Mmm. That's the STUFF!" << std::endl;
		std::cout << "<FR4G-TP; " << _name << "> ";
		std::cout << "heals " << n << " hit-points" << std::endl;
	}
	displayStatus();
}

void			FragTrap::vaulthunter_dot_exe(std::string const & tar) {
	if (arc4random() % 2) {
		meleeAttack(tar);
	} else {
		rangedAttack(tar);
	}
}

// --------------------------------------------------------- //
// ---- Getters and Setters								---- //
// --------------------------------------------------------- //

unsigned int	FragTrap::_get_hp(void) const {
	return _hp;
}

void			FragTrap::_set_hp(unsigned int nval) {
	_hp = nval;
}

unsigned int	FragTrap::_get_MAX_HP(void) const {
	return _MAX_HP;
}

void			FragTrap::_set_MAX_HP(unsigned int nval) {
	_MAX_HP = nval;
}

unsigned int	FragTrap::_get_energy(void) const {
	return _energy;
}

void			FragTrap::_set_energy(unsigned int nval) {
	_energy = nval;
}

unsigned int	FragTrap::_get_MAX_ENERGY(void) const {
	return _MAX_ENERGY;
}

void			FragTrap::_set_MAX_ENERGY(unsigned int nval) {
	_MAX_ENERGY = nval;
}

unsigned int	FragTrap::_get_level(void) const {
	return _level;
}

void			FragTrap::_set_level(unsigned int nval) {
	_level = nval;
}

std::string		FragTrap::_get_name(void) const {
	return _name;
}

void			FragTrap::_set_name(std::string const & nval) {
	_name = nval;
}

unsigned int	FragTrap::_get_melee_dmg(void) const {
	return _melee_dmg;
}

void			FragTrap::_set_melee_dmg(unsigned int nval) {
	_melee_dmg = nval;
}

unsigned int	FragTrap::_get_ranged_dmg(void) const {
	return _ranged_dmg;
}

void			FragTrap::_set_ranged_dmg(unsigned int nval) {
	_ranged_dmg = nval;
}

unsigned int	FragTrap::_get_armor(void) const {
	return _armor;
}

void			FragTrap::_set_armor(unsigned int nval) {
	_armor = nval;
}
