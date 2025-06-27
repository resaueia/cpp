/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:23:27 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/27 18:54:35 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		templates[i] = NULL;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.templates[i])
			this->templates[i] = other.templates[i]->clone();
		else
			this->templates[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (this->templates[i])
				delete this->templates[i];
			if (other.templates[i])
				this->templates[i] = other.templates[i]->clone();
			else
				this->templates[i] = NULL;
		}
	}
	std::cout << "MateriaSource assignment operator called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	if (this->templates)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->templates[i])
			{
				delete this->templates[i]; // Delete each AMateria in the templates
			}
		}
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!this->templates[i])
		{
			this->templates[i] = m;
			std::cout << "Learned materia: " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource is full, cannot learn more materias." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->templates[i] && this->templates[i]->getType() == type)
		{
			std::cout << "Creating materia of type: " << type << std::endl;
			return this->templates[i]->clone();
		}
	}
	std::cout << "Materia of type " << type << " not found." << std::endl;
	return NULL;
}