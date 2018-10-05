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
		
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & os, FragTrap const & that) {

	return os;
}

// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //

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
