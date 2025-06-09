/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:02:27 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/09 17:09:28 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Brain class implementation
Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

// Copy constructor
Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i]; // deep copy here too to make it explicit?
	}
}

// Assignment operator
Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i]; // this is what is called a deep copy
		}
	}
	return *this;
}

// Destructor
Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

/* GETTERS AND SETTERS */

// Set an idea at a specific index
void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100) {
		this->ideas[index] = idea;
	} else {
		std::cerr << "Index out of bounds" << std::endl;
	}
}

// Get an idea at a specific index
std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return this->ideas[index];
	} else {
		std::cerr << "Index out of bounds" << std::endl;
		return "";
	}
}