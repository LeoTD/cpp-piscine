#include <Pony.hpp>
#include <string>
#include <iostream>
#include <cstdlib>

Pony::~Pony() {
	std::cout << _name << " has died!" << std::endl;
}

Pony::Pony() {
	std::cout << "Default Pony!" << std::endl;
	_name = "Vex";
	_owner = "Percy";
	dexterity = 13;
	strength = 10;
	constitution = 16;
	wisdom = 7;
	charisma = 4;
	intelligence = 6;
	
	_MAX_HP = 0;
	for (int i = 0; i < constitution; i++) {
		_MAX_HP += (rand() % 6) + 1;
	}
	_HP = _MAX_HP;
	_MAX_MP = 0;
	for (int i = 0; i < intelligence || i < charisma; i++) {
		_MAX_MP += (rand() % 6) + 1;
	}
	_MP = _MAX_MP;
	_MAX_SPEED = 0;
	for (int i = 0; i < dexterity || i < strength; i++) {
		_MAX_SPEED += (rand() % 6) + 1;
	}
	_SPEED = 0;
	_CR = dexterity + strength + intelligence + wisdom + charisma + constitution;
	std::cout << _name << " is alive!" << std::endl;
}

Pony::Pony(std::string name, std::string owner, int stats[6]) {
	_name = name;
	_owner = owner;
	dexterity = stats[0];
	strength = stats[1];
	constitution = stats[2];
	charisma = stats[3];
	wisdom = stats[4];
	intelligence = stats[5];

	_MAX_HP = 0;
	for (int i = 0; i < constitution; i++) {
		_MAX_HP += (rand() % 6) + 1;
	}
	_HP = _MAX_HP;
	_MAX_MP = 0;
	for (int i = 0; i < intelligence || i < charisma; i++) {
		_MAX_MP += (rand() % 6) + 1;
	}
	_MP = _MAX_MP;
	_MAX_SPEED = 0;
	for (int i = 0; i < dexterity || i < strength; i++) {
		_MAX_SPEED += (rand() % 6) + 1;
	}
	_SPEED = 0;
	_CR = dexterity + strength + intelligence + wisdom + charisma + constitution;
	std::cout << _name << " is alive!" << std::endl;
}

int			Pony::stompAtk() {
	int damage;

	damage = ((rand() % 6) + 1) * strength;
	std::cout << "STOMP ATTACK! " << damage << " damage!" << std::endl;
	return damage;
}

void		Pony::emote() {
	if (wisdom > 10) {
		std::cout << "A pony is a childhood dream. A horse is an adulthood treasure." << std::endl;
		return ;
	} else {
		std::cout << "* whinny intensifies *" << std::endl;
	}
}

void		Pony::gallop() {
	_SPEED++;
	if (_SPEED > _MAX_SPEED) {
		_SPEED = _MAX_SPEED;
	}
}

void		Pony::displayStatus() {
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Owner: " << _owner << std::endl;
	std::cout << "con: " << constitution << std::endl;
	std::cout << "str: " << strength << std::endl;
	std::cout << "dex: " << dexterity << std::endl;
	std::cout << "int: " << intelligence << std::endl;
	std::cout << "wis: " << wisdom << std::endl;
	std::cout << "cha: " << charisma << std::endl;
	std::cout << "Challenge Rating: " << _CR << std::endl;
}