#include <Brain.hpp>
#include <iostream>
#include <sstream>

Brain::Brain() {}

Brain::~Brain() {}

std::string			Brain::identify() const {
	std::stringstream	stream;
	std::string			str;

	stream << this << std::endl;
	stream >> str;
	return str;
}