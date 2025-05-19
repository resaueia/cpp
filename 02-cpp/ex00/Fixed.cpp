/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:49:11 by rsaueia           #+#    #+#             */
/*   Updated: 2025/05/19 18:53:29 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


// Default constructor
// Initializes rawBits_ to 0 then prints a message
// This constructor is called when an object of type Fixed is created without any arguments
Fixed::Fixed() : rawBits_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
// Initializes rawBits_ to the value of the rawBits_ member of the object being copied
// This constructor is called when an object of type Fixed is created as a copy of another object
Fixed::Fixed(const Fixed& other) : rawBits_(other.rawBits_)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
// Assigns the value of the rawBits_ member of the object being copied to the current object
// This operator is called when an existing object of type Fixed is assigned the value of another object
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) // Check for self-assignment
	{
		this->rawBits_ = other.rawBits_;
	}
	return *this; // Return the current object and allows chaining (a = b = c)
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Getter for rawBits_
// Returns the value of the rawBits_ member
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits_;
}

// Setter for rawBits_
// Sets the value of the rawBits_ member to the given value
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits_ = raw;
}