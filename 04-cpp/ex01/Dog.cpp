/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:47:24 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/09 17:11:27 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// default constructor
Dog::Dog() : Animal() {
	this->type = "Dog";
	this->brain = new Brain(); // Initialize the Brain pointer
	std::cout << "Dog default constructor called" << std::endl;
}

// copy constructor
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain); // Deep copy of the Brain pointer
}

// assignment operator
Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		if (this->brain) // Check if the Brain pointer is already allocated
			delete this->brain; // Free the existing Brain pointer
		this->brain = new Brain(*other.brain); // Deep copy of the Brain pointer
		std::cout << "Dog assignment operator deep copy called" << std::endl;
	}
	return *this;
}

// destructor
Dog::~Dog() {
	delete this->brain; // Free the Brain pointer
	std::cout << "Dog destructor called" << std::endl;
}

// makeSound method
void Dog::makeSound() const{
	std::cout << "Woof! Woof!" << std::endl;
	std::cout << " /^ ^\\ " << std::endl;
	std::cout << "/ 0 0 \\" << std::endl;
	std::cout << "V\\ Y /V" << std::endl;
	std::cout << "------------------------" << std::endl;
}

std::string Dog::getType() const{
	return this->type;
}


// Getter for the Brain pointer
Brain* Dog::getBrain() const {
	return this->brain;
}