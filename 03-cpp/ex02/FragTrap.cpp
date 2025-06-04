/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:54:09 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/04 16:20:10 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// default constructor
FragTrap::FragTrap() : ClapTrap("DefaultFragTrap")
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called." << std::endl;
}

// constructor with name parameter
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap constructor called for " << name << "." << std::endl;
}

// copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called for " << other.name << "." << std::endl;
}

// assignment operator
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "FragTrap assignment operator called for " << other.name << "." << std::endl;
	}
	return (*this);
}

// destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << name << "." << std::endl;
}

/* unique methods */

// attack method
void FragTrap::attack(const std::string &target)
{
	if (energyPoints > 0)
	{
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else
	{
		std::cout << "FragTrap " << name << " is out of energy and cannot attack!" << std::endl;
	}
}

// highFivesGuys method
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}

// getters for debugging

int FragTrap::getEnergyPoints()
{
	return energyPoints;
}