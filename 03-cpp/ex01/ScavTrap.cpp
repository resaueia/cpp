/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:02:29 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/02 19:21:19 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("Default ScavTrap")
{
	this->hitPoints = 100;   // ScavTrap has more hit points
	this->energyPoints = 50; // ScavTrap has more energy points
	this->attackDamage = 20; // ScavTrap has more attack damage
	std::cout << "ScavTrap default constructor called." << std::endl;
}

// Constructor with name parameter
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap constructor called for " << name << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

// Assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other); // Call ClapTrap's assignment operator
	}
	std::cout << "ScavTrap assignment operator called." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target
				  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " cannot attack!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (this->hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " cannot enter Gate Keeper mode because it is destroyed!" << std::endl;
	}
}
