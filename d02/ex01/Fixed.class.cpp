#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

int const		Fixed::_fractionalBits = 8;

Fixed::Fixed(): _value(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const n)
	: _value(n * (1 << _fractionalBits))
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const n)
	: _value(roundf(n * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
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

std::ostream &	operator<<(std::ostream & os, Fixed const & that) {
	os << that.toFloat();
	return os;
}

int				Fixed::getRawBits() const {
	std::cout << "getRawBits called" << std::endl;
	return _value;
}

void			Fixed::setRawBits(int const n) {
	std::cout << "setRawBits called" << std::endl;
	_value = n;
	return ;
}

int				Fixed::toInt() const {
	return (_value / (1 << _fractionalBits));
}

float			Fixed::toFloat() const {
	return (float(_value) / (1 << _fractionalBits));
}
