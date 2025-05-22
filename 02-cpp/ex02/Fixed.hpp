/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:32:43 by rsaueia           #+#    #+#             */
/*   Updated: 2025/05/22 16:49:29 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int rawBits_;  // the fixed-point value stored as an integer
	static const int fracBits_ = 8; // how many bits are for the fractional part

  public:
	// 1) Default constructor:
	//    Initialize rawBits_ to 0 (represents 0.0 in fixed-point)
	Fixed();

	// 2) Copy constructor:
	//    Create a new Fixed by copying the rawBits_ from 'other'
	Fixed(const Fixed &other);

	// 3) Constructor from int:
	//    Convert an integer 'intValue' to fixed-point by shifting left
	explicit Fixed(int const intValue); // the explicit keyword prevents implicit conversions (e.g. Fixed a = 5 -> Fixed a(5);)
    
	// 4) Constructor from float:
    //    Convert a float into fixed-point by multiplying by 2^fracBits_ and rounding.
    explicit Fixed(float const floatValue);

	// 5) Copy assignment operator:
    //    Defines what happens when you write c = b;
    Fixed& operator=(Fixed const& other);

    // 6) Destructor:
    //    Called when a Fixed object goes out of the scope or is deleted.
    ~Fixed();

	// 7) Convert to float: reverse fixed-point scaling
	float toFloat(void) const;

	// 8) Convert to int: discard fractional bits
	int toInt(void) const;

	// 9) Comparison operator >
    bool operator>(Fixed const& other) const;

	// 10) Comparison operator <
	bool operator<(Fixed const& other) const;

	// 11) Comparison operator >=
	bool operator>=(Fixed const& other) const;

	// 12) Comparison operator <=
	bool operator<=(Fixed const& other) const;

	// 13) Comparison operator ==
	bool operator==(Fixed const& other) const;

	// 14) Comparison operator !=
	bool operator!=(Fixed const& other) const;

	// Arithmetic operators
	
	// 15) Addition operator +
	Fixed operator+(Fixed const& other) const;

	// 16) Subtraction operator -
	Fixed operator-(Fixed const& other) const;

	// 17) Multiplication operator *
	Fixed operator*(Fixed const& other) const;
	
	// 18) Division operator /
	Fixed operator/(Fixed const& other) const;
};

//    Overload of operator<<
//    Inserts the float representation of the Fixed object into the output stream.
std::ostream& operator<<(std::ostream& os, Fixed const& f);

#endif // FIXED_HPP