/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:52:44 by rsaueia           #+#    #+#             */
/*   Updated: 2025/05/21 18:39:50 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// 1) Default constructor
//    Initialize rawBits_ to 0, representing 0.0 in fixed-point.
Fixed::Fixed() : rawBits_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// 2) Copy constructor
//    Copy the rawBits_ from 'other', so this object becomes an exact clone.
Fixed::Fixed(const Fixed &other) : rawBits_(other.rawBits_)
{
	std::cout << "Copy constructor called" << std::endl;
}

// 3) Constructor from int
//    Convert integer into fixed-point by shifting left fracBits_ (×2^8).
Fixed::Fixed(int const intValue) : rawBits_(intValue << fracBits_)
{
	std::cout << "Int constructor called" << std::endl;
}

// 4) Constructor from float
//    Multiply the float by 2^fracBits_ (shifts the binary point right),
//    round to the nearest integer, and store in rawBits_.
Fixed::Fixed(float const floatValue) : rawBits_(static_cast<int>(roundf(floatValue
			* (1 << fracBits_))))
{
	std::cout << "Float constructor called" << std::endl;
}

// 5) Copy assignment operator
//    Handles the case c = b; by copying rawBits_ from 'other'.
Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	// avoid self-assignment (a = a)
	if (this != &other)
	{
		this->rawBits_ = other.rawBits_;
	}
	return (*this); // allow chaining: a = b = c;
}

// 6) Destructor
//    Called automatically when an object goes out of scope.
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// 7) toFloat: convert rawBits_ back to float by dividing by 2^fracBits_
float Fixed::toFloat(void) const
{
	// rawBits_ stores value * 256 (2^8)
	return (rawBits_ / static_cast<float>(1 << fracBits_));
}

// 8) toInt: convert rawBits_ back to int by shifting right fracBits_ bits
int Fixed::toInt(void) const
{
	// shift right discards the fractional component
	return (rawBits_ >> fracBits_);
}

// 9)Overload of operator<<
// Inserts the float representation of f into the output stream.
std::ostream &operator<<(std::ostream &os, Fixed const &f)
{
	os << f.toFloat();
	return (os);
}
