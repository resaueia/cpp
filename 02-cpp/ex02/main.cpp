/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:40:54 by rsaueia           #+#    #+#             */
/*   Updated: 2025/05/22 16:54:34 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a(5);    // int constructor → a = 5.0
	Fixed b(2.5f); // float constructor → b = 2.5
	// Test all arithmetic operators
	Fixed sum = a + b;  // should be 7.5
	Fixed diff = a - b; // should be 2.5
	Fixed prod = a * b; // should be 12.5
	Fixed quot = a / b; // should be 2.0
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "a + b = " << sum << std::endl;
	std::cout << "a - b = " << diff << std::endl;
	std::cout << "a * b = " << prod << std::endl;
	std::cout << "a / b = " << quot << std::endl;
	return (0);
}
