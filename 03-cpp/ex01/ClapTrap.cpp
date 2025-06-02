/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:51:53 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/02 17:19:31 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// default constructor
ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " created." << std::endl;
}

// constructor with name parameter
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " created." << std::endl;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) 
	: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << "ClapTrap " << this->name << " copied." << std::endl;
}

// assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if(this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap assignment operator called." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destroyed." << std::endl;
}

/* METHODS */


// Attacks a target, reducing energy points and printing a message
void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout << "ClapTrap " << this->name << " attacks " << target 
				  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	} 
	else {
		std::cout << "ClapTrap " << this->name << " cannot attack!" << std::endl;
	}
}

// Takes damage, reducing hit points and printing a message
void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is already destroyed!" << std::endl;
		return;
	}
	this->hitPoints -= amount;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
}

// Repairs itself, increasing hit points (if energy is available) and printing a message
void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " cannot be repaired! No energy or it is already destroyed." << std::endl;
		return;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " repairs itself for " << amount 
			  << " hit points!" << std::endl;
}


/* name getter just for debugging purposes */
std::string ClapTrap::getName() const {
	return this->name;
}

int ClapTrap::getHitPoints() const {
	return this->hitPoints;
}
