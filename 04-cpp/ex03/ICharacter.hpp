/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:39:01 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/27 17:41:58 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0; // Returns the character's name
		virtual void equip(AMateria* m) = 0; // Equips a materia
		virtual void unequip(int idx) = 0; // Unequips a materia at the given index
		virtual void use(int idx, ICharacter& target) = 0; // Uses a materia on the target character
};

#endif