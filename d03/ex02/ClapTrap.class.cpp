#include "ClapTrap.class.hpp"

// --------------------------------------------------------- //
// ---- Constructors and Init							---- //
// --------------------------------------------------------- //

void		ClapTrap::init(void) {
	_set_hp(100);
	_set_MAX_HP(100);
	_set_energy(100);
	_set_MAX_ENERGY(100);
	_set_level(1);
	_set_melee_dmg(30);
	_set_ranged_dmg(20);
	_set_armor(5);
	_set_type("CL4P-TP");

	_meleeMessage[0] = "Take THAT!";
	_meleeMessage[1] = "There is no way this ends badly!";
	_meleeMessage[2] = "WOW! I hit 'em!";

	_rangedMessage[0] = "250 shots per second, ONE KILL!";
	_rangedMessage[1] = "Let's get this party started!";
	_rangedMessage[2] = "Flesh fireworks!";

	_damageMessage[0] = "* angry dead robot noises *";
	_damageMessage[1] = "Ouch! Watch it! This is a vintage chasis!";
	_damageMessage[2] = "AaAaHHH!!!111!1brrrzzzttt...";

	_repairMessage[0] = "I'm UNSTOPPABLE! HAhahaha!" ;
	_repairMessage[1] = "* Windows Startup Noise *";
	_repairMessage[2] = "Mmm. That's the STUFF!";

}

ClapTrap::ClapTrap()
	:	_name("ClapTrap")
{
	init();
	return ;
}

ClapTrap::ClapTrap(std::string name)
	:	_name(name)
{
	init();
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & that) {
	*this = that;
	return ;
}

ClapTrap::~ClapTrap() {

	return ;
}

// --------------------------------------------------------- //
// ---- Operators										---- //
// --------------------------------------------------------- //

ClapTrap &	ClapTrap::operator=(ClapTrap const & that) {
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

std::ostream &	operator<<(std::ostream & os, ClapTrap const & that) {
	os << that._get_name();
	return os;
}

// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //

void				ClapTrap::displayStatus() const {
	std::cout << "<" << _get_type() << " " << _name << "> ";
	std::cout << "HP: ";
	if (_hp == 0) {
		std::cout << "\033[91m\033[1m";
	}
	std::cout << _hp << "/" << _MAX_HP << " \033[0m";
	std::cout << "ENERGY: " << _energy << "/" << _MAX_ENERGY << " ";
	std::cout << "ARMOR: " << _armor << " ";
	std::cout << std::endl;
}

void				ClapTrap::meleeAttack(std::string const & tar) const {
	unsigned int		r = arc4random() % 3;

	std::cout << "<" << _get_type() << "; " << _name << "> ";
	switch(r) {
		case 0:
			std::cout << _meleeMessage[r] << std::endl;
			break ;
		case 1:
			std::cout << _meleeMessage[r] << std::endl;
			break ;
		case 2:
			std::cout << _meleeMessage[r] << std::endl;
			break ;
	}
	std::cout << "<Headbutt> deals " << _melee_dmg << " damage";
	std::cout << " to " << tar << std::endl;
	displayStatus();
	return ;
}

void				ClapTrap::rangedAttack(std::string const & tar) const {
	unsigned int		r = arc4random() % 4;

	std::cout << "<" << _get_type() << "; " << _name << "> ";
	switch(r) {
		case 0:
			std::cout << _rangedMessage[r] << std::endl;
			break ;
		case 1:
			std::cout << _rangedMessage[r] << std::endl;
			break ;
		case 2:
			std::cout << _rangedMessage[r] << std::endl;
			break ;
	}
	std::cout << "<Minigun> deals " << _ranged_dmg << " damage";
	std::cout << " to " << tar << std::endl;
	displayStatus();
	return ;
}

void				ClapTrap::takeDamage(unsigned int n) {
	if (_hp == 0) {
		std::cout << "<" << _get_type() << "; " << _name << "> ";
		std::cout << _damageMessage[0] << std::endl;
		std::cout << "<" << _get_type() << "; " << _name << "> ";
		std::cout << "takes " << n << " overkill damage" << std::endl;
		return ;
	}
	if (n >= (_hp + _armor)) {
		_hp = 0;
	} else {
		_hp -= (n - _armor);
	}
	if (_hp > 0) {
		std::cout << "<" << _get_type() << "; " << _name << "> ";
		std::cout << _damageMessage[1] << std::endl;
		std::cout << "<" << _get_type() << "; " << _name << "> ";
		std::cout << "takes " << n << " damage" << std::endl;
	} else {
		std::cout << "<" << _get_type() << "; " << _name << "> ";
		std::cout << _damageMessage[2] << std::endl;
		std::cout << "<" << _get_type() << "; " << _name << "> ";
		std::cout << "takes " << n << " damage" << std::endl;
	}
	displayStatus();
}

void				ClapTrap::beRepaired(unsigned int n) {
	if ((_hp + n) > _MAX_HP) {
		_hp = _MAX_HP;
	} else {
		_hp += n;
	}
	if (_hp == _MAX_HP) {
		std::cout << "<" << _get_type() << "; " << _name << "> ";
		std::cout << _repairMessage[0] << std::endl;
		std::cout << "<" << _get_type() << "; " << _name << "> ";
		std::cout << "heals " << n << " hit-points" << std::endl;
	} else if (_hp == n) {
		std::cout << "<" << _get_type() << "; " << _name << "> ";
		std::cout << _repairMessage[1] << std::endl;
		std::cout << "<" << _get_type() << "; " << _name << "> ";
		std::cout << "heals " << n << " hit-points" << std::endl;
	} else {
		std::cout << "<" << _get_type() << "; " << _name << "> ";
		std::cout << _repairMessage[2] << std::endl;
		std::cout << "<" << _get_type() << "; " << _name << "> ";
		std::cout << "heals " << n << " hit-points" << std::endl;
	}
	displayStatus();
}

// --------------------------------------------------------- //
// ---- Getters and Setters								---- //
// --------------------------------------------------------- //

unsigned int	ClapTrap::_get_hp(void) const {
	return _hp;
}

void			ClapTrap::_set_hp(unsigned int nval) {
	_hp = nval;
}

unsigned int	ClapTrap::_get_MAX_HP(void) const {
	return _MAX_HP;
}

void			ClapTrap::_set_MAX_HP(unsigned int nval) {
	_MAX_HP = nval;
}

unsigned int	ClapTrap::_get_energy(void) const {
	return _energy;
}

void			ClapTrap::_set_energy(unsigned int nval) {
	_energy = nval;
}

unsigned int	ClapTrap::_get_MAX_ENERGY(void) const {
	return _MAX_ENERGY;
}

void			ClapTrap::_set_MAX_ENERGY(unsigned int nval) {
	_MAX_ENERGY = nval;
}

unsigned int	ClapTrap::_get_level(void) const {
	return _level;
}

void			ClapTrap::_set_level(unsigned int nval) {
	_level = nval;
}

std::string		ClapTrap::_get_name(void) const {
	return _name;
}

void			ClapTrap::_set_name(std::string const & nval) {
	_name = nval;
}

unsigned int	ClapTrap::_get_melee_dmg(void) const {
	return _melee_dmg;
}

void			ClapTrap::_set_melee_dmg(unsigned int nval) {
	_melee_dmg = nval;
}

unsigned int	ClapTrap::_get_ranged_dmg(void) const {
	return _ranged_dmg;
}

void			ClapTrap::_set_ranged_dmg(unsigned int nval) {
	_ranged_dmg = nval;
}

unsigned int	ClapTrap::_get_armor(void) const {
	return _armor;
}

void			ClapTrap::_set_armor(unsigned int nval) {
	_armor = nval;
}

std::string		ClapTrap::_get_type(void) const {
	return _type;
}

void			ClapTrap::_set_type(std::string const & nval) {
	_type = nval;
}
