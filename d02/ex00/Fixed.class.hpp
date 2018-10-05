#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
public:
	Fixed();
	Fixed(int const);
	Fixed(Fixed const &);
	Fixed & operator=(Fixed const &);
	~Fixed();

	int					getRawBits(void) const;
	void				setRawBits(int const);

private:
	static int const	_fractionalBits;
	int					_value;
};

#endif
