/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:46:34 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/27 19:06:47 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4]; // Array to hold up to 4 materias
	public:
		Character(std::string const & name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		virtual ~Character();

		std::string const & getName() const; // Returns the character's name
		void equip(AMateria* m); // Equips a materia
		void unequip(int idx); // Unequips a materia at the given index
		void use(int idx, ICharacter& target); // Uses a materia on the target character

		//AMateria* getInventorySlot(int i) const { return inventory[i]; }

};

#endif