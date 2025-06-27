/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:49:39 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/27 18:52:44 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name)
{
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = NULL;
	std::cout << "Character constructor called for: " << name << std::endl;
}

Character::Character(const Character &other) : name(other.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if(other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	std::cout << "Character assignment operator called for: " << this->name << std::endl;
	return *this;
}

Character::~Character()
{
	if (this->inventory)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->inventory[i]; // Delete each AMateria in the inventory
		}
	}
	std::cout << "Character destructor called for: " << this->name << std::endl;
}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if(!this->inventory[i])
		{
			this->inventory[i] = m;
			std::cout << this->name << " equipped " << m->getType() << " at index " << i << std::endl;
			return;
		}
	}
	std::cout << "Inventory is full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !this->inventory[idx])
	{
		std::cout << "Invalid index or no materia to unequip at index " << idx << std::endl;
		return;
	}
	std::cout << this->name << " unequipped " << this->inventory[idx]->getType() << " from index " << idx << std::endl;
	this->inventory[idx] = NULL; // Set the inventory slot to NULL
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !this->inventory[idx])
	{
		std::cout << "Invalid index or no materia to use at index " << idx << std::endl;
		return;
	}
	std::cout << this->name << " uses " << this->inventory[idx]->getType() << " on " << target.getName() << std::endl;
	this->inventory[idx]->use(target);
}