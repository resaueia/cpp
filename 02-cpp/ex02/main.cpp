/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:40:54 by rsaueia           #+#    #+#             */
/*   Updated: 2025/05/22 18:21:44 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed x( 3.5f );
    Fixed y( 7.25f );
    Fixed const cx( 2.0f );
    Fixed const cy( 5.0f );

    std::cout << "min(x, y)       = " << Fixed::min(x, y) << std::endl;   // 3.5
    std::cout << "max(x, y)       = " << Fixed::max(x, y) << std::endl;   // 7.25
    std::cout << "min(cx, cy)     = " << Fixed::min(cx, cy) << std::endl; // 2.0
    std::cout << "max(cx, cy)     = " << Fixed::max(cx, cy) << std::endl; // 5.0
}
