#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed{
	private:
	int 				rawBits_;
	static const int	fractionalBits_ = 8;

	public:
	Fixed(); // Default constructor
	Fixed(const Fixed& other); // Copy constructor
	Fixed& operator=(const Fixed& other); // Copy assignment operator
	~Fixed(); // Destructor

	int getRawBits(void) const; // Getter for rawBits_
	void setRawBits(int const raw); // Setter for rawBits_
};

#endif