/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:13:56 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/04 18:10:20 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//default constructor
Animal::Animal() : type("Thing") {
	std::cout << "Animal default constructor called" << std::endl;
}

// construcotor with name param
/*Animal::Animal(std::string name) : type(name) {
	std::cout << "Animal constructor with name param called" << std::endl;
}*/

// copy constructor
Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

// assignment operator
Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

// destructor
Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

// makeSound method
void Animal::makeSound() const{
	std::cout << "Animal makes a generic sound" << std::endl;
}

// getType method
std::string Animal::getType() const{
	return this->type;
}