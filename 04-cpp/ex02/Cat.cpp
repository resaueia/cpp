/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:34:27 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/09 17:11:02 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// default constructor
Cat::Cat() : Animal() {
	this->type = "Cat";
	this->brain = new Brain(); // Initialize the Brain pointer
	std::cout << "Cat default constructor called" << std::endl;
}

// copy constructor
Cat::Cat(const Cat& other) : Animal(other) {
	this->brain = new Brain(*other.brain); // Deep copy of the Brain pointer
	std::cout << "Cat copy constructor called" << std::endl;
}

// assignment operator
Cat& Cat::operator=(const Cat& other) {
	if (this != &other) 
	{
		Animal::operator=(other);
		if (this->brain)
			delete this->brain; // Free the existing Brain pointer
		this->brain = new Brain(*other.brain); // Deep copy of the Brain pointer
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

// destructor
Cat::~Cat() {
	delete this->brain; // Free the Brain pointer
	std::cout << "Cat destructor called" << std::endl;
}

// makeSound method
void Cat::makeSound() const{
	std::cout << "Meow!" << std::endl;
	std::cout << " /\\_/\\" << std::endl;  
	std::cout << "( o.o )" << std::endl; 
 	std::cout << " > ^ <" << std::endl;
	std::cout << "------------------------" << std::endl;
}

std::string Cat::getType() const{
	return this->type;
}

// Getter for the Brain pointer
Brain* Cat::getBrain() const {
	return this->brain;
}