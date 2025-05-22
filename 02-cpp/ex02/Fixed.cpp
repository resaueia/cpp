/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:36:05 by rsaueia           #+#    #+#             */
/*   Updated: 2025/05/22 18:21:16 by rsaueia          ###   ########.fr       */
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

// 9)Comparison operator >
// Returns true if this fixed-point value is greater than other.
bool Fixed::operator>(Fixed const &other) const
{
	return (this->rawBits_ > other.rawBits_);
}

// 10) Comparison operator <
// Returns true if this fixed-point value is less than other.
bool Fixed::operator<(Fixed const &other) const
{
	return (this->rawBits_ < other.rawBits_);
}

// 11) Comparison operator >=
// Returns true if this fixed-point value is greater than or equal to other.
bool Fixed::operator>=(Fixed const &other) const
{
	return (this->rawBits_ >= other.rawBits_);
}

// 12) Comparison operator <=
// Returns true if this fixed-point value is less than or equal to other.
bool Fixed::operator<=(Fixed const &other) const
{
	return (this->rawBits_ <= other.rawBits_);
}

// 13) Comparison operator ==
// Returns true if this fixed-point value is equal to other.
bool Fixed::operator==(Fixed const &other) const
{
	return (this->rawBits_ == other.rawBits_);
}

// 14) Comparison operator !=
// Returns true if this fixed-point value is not equal to other.
bool Fixed::operator!=(Fixed const &other) const
{
	return (this->rawBits_ != other.rawBits_);
}

/****** ARITHMETIC OPERATORS ******/

// 15) Addition operator +
// Returns a Fixed whose rawBits_ is the sum of the two operands.
Fixed Fixed::operator+(Fixed const &other) const
{
	Fixed result; // default constructor yields rawBits_ = 0
	result.rawBits_ = this->rawBits_ + other.rawBits_;
	return (result);
}

// 16) Subtraction operator -
// Returns a Fixed whose rawBits_ is the difference of the two operands.
Fixed Fixed::operator-(Fixed const &other) const
{
	Fixed result; // default constructor yields rawBits_ = 0
	result.rawBits_ = this->rawBits_ - other.rawBits_;
	return (result);
}

// 17) Multiplication operator * (pre-scaling strategy)
// Returns a Fixed whose rawBits_ is the product of the two operands.
Fixed Fixed::operator*(Fixed const &other) const
{
	Fixed result;
	long long temp = static_cast<long long>(rawBits_) * other.rawBits_;
	// after multiplying, shift back by fracBits_ to keep scale
	result.rawBits_ = static_cast<int>(temp >> fracBits_);
	return (result);
}

// 18) Division operator / (post-dislocation strategy)
// Returns a Fixed whose rawBits_ is the quotient of the two operands.
Fixed Fixed::operator/(Fixed const &other) const
{
	Fixed result;
	// pre-shift numerator to preserve precision, then divide
    long long temp = (static_cast<long long>(rawBits_) << fracBits_) / other.rawBits_;
    result.rawBits_ = static_cast<int>(temp);
	return (result);
}

/* INCREMENT AND DECREMENT */

// 19) Pre-increment operator ++
// Increments the fixed-point value by 1 and returns the updated object.
Fixed &Fixed::operator++()
{
	++rawBits_; // increment rawBits_ directly
	return (*this);
}

// 20) Post-increment operator ++ (postfix)
// Increments the fixed-point value by 1 and returns a copy of the original.
Fixed Fixed::operator++(int)
{
	Fixed temp(*this); // make a copy of the current object
	++rawBits_; // increment rawBits_ directly
	return (temp); // return the copy
}

// 21) Pre-decrement operator --
// Decrements the fixed-point value by 1 and returns the updated object.
Fixed &Fixed::operator--()
{
	--rawBits_; // decrement rawBits_ directly
	return (*this);
}

// 22) Post-decrement operator -- (postfix)
// Decrements the fixed-point value by 1 and returns a copy of the original.
Fixed Fixed::operator--(int)
{
	Fixed temp(*this); // make a copy of the current object
	--rawBits_; // decrement rawBits_ directly
	return (temp); // return the copy
}

/* MIN AND MAX */

// Static min (non-const)
// Returns the smaller of two Fixed objects.
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

// Static min (const)
// Returns the smaller of two const Fixed objects.
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

// Static max (non-const)
// Returns the larger of two Fixed objects.
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

// Static max (const)
// Returns the larger of two const Fixed objects.
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

// Overload of operator<<
// Inserts the float representation of f into the output stream.
std::ostream &operator<<(std::ostream &os, Fixed const &f)
{
	os << f.toFloat();
	return (os);
}