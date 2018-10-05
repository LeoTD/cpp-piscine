#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();
	explicit Fixed(int const);
	explicit Fixed(float const);
	explicit Fixed(Fixed const &);
	Fixed & operator=(Fixed const &);
	~Fixed();

	int					getRawBits(void) const;
	void				setRawBits(int const);

	float				toFloat(void) const;
	int					toInt(void) const;

private:
	static int const	_fractionalBits;
	int					_value;
};

std::ostream &		operator<<(std::ostream &, Fixed const &);

#endif
