#include "Fixed.class.hpp"
#include <iostream>

Fixed::Fixed(): _value(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const n): _value(n) {
	std::cout << "Assign constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & that) {
	std::cout << "Copy constructor called" << std::endl;
	*this = that;
	return ;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;

	return ;
}

Fixed &	Fixed::operator=(Fixed const & that) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &that) {
		_value = that.getRawBits();
	}
	return *this;
}

int const		Fixed::_fractionalBits = 8;

int				Fixed::getRawBits() const {
	std::cout << "getRawBits called" << std::endl;
	return _value;
}

void			Fixed::setRawBits(int const n) {
	std::cout << "setRawBits called" << std::endl;
	_value = n;
	return ;
}
