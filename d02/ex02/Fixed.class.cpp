#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

int const		Fixed::_fractionalBits = 8;

Fixed::Fixed(): _value(0) {
	return ;
}

Fixed::Fixed(int const n)
	: _value(n * (1 << _fractionalBits))
{
	return ;
}

Fixed::Fixed(float const n)
	: _value(roundf(n * (1 << _fractionalBits)))
{
	return ;
}

Fixed::Fixed(Fixed const & that) {
	*this = that;
	return ;
}

Fixed::~Fixed() {
	return ;
}

Fixed &	Fixed::operator=(Fixed const & that) {
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
	return _value;
}

void			Fixed::setRawBits(int const n) {
	_value = n;
	return ;
}

int				Fixed::toInt() const {
	return (_value / (1 << _fractionalBits));
}

float			Fixed::toFloat() const {
	return (float(_value) / (1 << _fractionalBits));
}

bool	 Fixed::operator>(Fixed const & that) {
	return (this->getRawBits() > that.getRawBits());
}

bool	 Fixed::operator<(Fixed const & that) {
	return (this->getRawBits() < that.getRawBits());
}

bool	 Fixed::operator>=(Fixed const & that) {
	return (this->getRawBits() >= that.getRawBits());
}

bool	 Fixed::operator<=(Fixed const & that) {
	return (this->getRawBits() <= that.getRawBits());
}

bool	 Fixed::operator==(Fixed const & that) {
	return (this->getRawBits() == that.getRawBits());
}

bool	 Fixed::operator!=(Fixed const & that) {
	return (this->getRawBits() != that.getRawBits());
}

Fixed &		Fixed::operator+(Fixed const & that) {
	long long a(this->getRawBits());
	long long b(that.getRawBits());

	this->setRawBits( (int)(a + b) );

	return *this;
}

Fixed &		Fixed::operator-(Fixed const & that) {
	long long a(this->getRawBits());
	long long b(that.getRawBits());

	this->setRawBits( (int)(a - b) );

	return *this;
}

Fixed &		Fixed::operator/(Fixed const & that) {
	long long a(this->getRawBits());
	long long b(that.getRawBits());

	this->setRawBits( (int)((a * (1 << _fractionalBits)) / b) );

	return *this;
}

Fixed &		Fixed::operator*(Fixed const & that) {
	long long a(this->getRawBits());
	long long b(that.getRawBits());

	this->setRawBits( (int)((a * b) / (1 << _fractionalBits)) );

	return *this;
}

Fixed &		Fixed::operator++(void) {
	this->setRawBits(_value + 1);
	return *this;
}

Fixed &		Fixed::operator--(void) {
	this->setRawBits(_value - 1);
	return *this;
}

Fixed		Fixed::operator++(int) {
	Fixed prev = *this;

	this->setRawBits(_value + 1);
	return prev;
}

Fixed		Fixed::operator--(int) {
	Fixed prev = *this;

	this->setRawBits(_value - 1);
	return prev;
}

// --------------------------------------------- //
// ---- Min and Max functions				---- //
// --------------------------------------------- //

Fixed &				Fixed::min(Fixed & a, Fixed & b) {
	if (a.getRawBits() < b.getRawBits()) {
		return a;
	} else {
		return b;
	}
}

Fixed const &		Fixed::min(Fixed const & a, Fixed const & b) {
	if (a.getRawBits() < b.getRawBits()) {
		return a;
	} else {
		return b;
	}
}

Fixed &				Fixed::max(Fixed & a, Fixed & b) {
	if (a.getRawBits() < b.getRawBits()) {
		return b;
	} else {
		return a;
	}
}

Fixed const &		Fixed::max(Fixed const & a, Fixed const & b) {
	if (a.getRawBits() < b.getRawBits()) {
		return b;
	} else {
		return a;
	}
}
