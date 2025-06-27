/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:12:08 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/27 16:35:12 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

// This is an abstract class and it acts as an interface for all materia types.
// It can't be instantiated, yet it performs the usual class behavior,
// such as storing a type and providing a clone method.
// It forces derived classes to implement the virtual methods.

class ICharacter; // Forward declaration of ICharacter

class AMateria
{
	protected: // we use protected to allow derived classes to access the type directly
		std::string type;
	public:
		AMateria(std::string const & type);
		virtual ~AMateria();

		std::string const & getType() const; // Returns the materia type

		virtual AMateria* clone() const = 0; // Returns a new instance of the same type
		virtual void use(ICharacter& target); // Uses the materia on the target character
};

// If a method is pure virtual, it is declared with "= 0" at the end of its declaration
// This means that the method MUST be implemented by any derived class.

#endif