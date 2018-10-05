#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();
	explicit Fixed(int const);
	explicit Fixed(float const);
	Fixed(Fixed const &);
	Fixed & operator=(Fixed const &);
	~Fixed();

	int					getRawBits(void) const;
	void				setRawBits(int const);

	float				toFloat(void) const;
	int					toInt(void) const;

	bool	operator>(Fixed const &);
	bool	operator<(Fixed const &);
	bool	operator>=(Fixed const &);
	bool	operator<=(Fixed const &);
	bool	operator==(Fixed const &);
	bool	operator!=(Fixed const &);

	Fixed &	operator+(Fixed const &);
	Fixed &	operator-(Fixed const &);
	Fixed &	operator/(Fixed const &);
	Fixed &	operator*(Fixed const &);

	Fixed &	operator++(void);
	Fixed &	operator--(void);
	Fixed	operator++(int); //post-increment
	Fixed	operator--(int);

	static Fixed &			min(Fixed &, Fixed &);
	static Fixed const &	min(Fixed const &, Fixed const &);
	static Fixed &			max(Fixed &, Fixed &);
	static Fixed const &	max(Fixed const &, Fixed const &);

private:
	static int const	_fractionalBits;
	int					_value;
};

std::ostream &		operator<<(std::ostream &, Fixed const &);


#endif
