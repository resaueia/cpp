/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:34:27 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/04 18:26:34 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// default constructor
Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

// copy constructor
Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
}

// assignment operator
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

// destructor
Cat::~Cat() {
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