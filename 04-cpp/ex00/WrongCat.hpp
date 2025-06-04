/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:39:14 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/04 19:40:56 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		~WrongCat();
		void makeSound() const; // same method, yet it lacks the virtual keyword, hence failing to override the base method
};
#endif

/* The `virtual` keyword enables dynamic dispatch in C++, allowing derived classes 
to override base class methods. It's essential when using base class pointers 
or references to ensure the correct method is called based on the actual object type. 
Always use `virtual` for polymorphic behavior and destructors in base classes.
It allows for the compiler to determine at runtime which method to call,
ensuring that the most derived version of the method is executed,
even when using a base class pointer or reference.
*/