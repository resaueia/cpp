/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:08:16 by rsaueia           #+#    #+#             */
/*   Updated: 2025/09/28 15:09:30 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }

Intern::~Intern() {}

// Funções auxiliares para criação
static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// now for the actual importatn function

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    // Lista de nomes conhecidos
    std::string names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // Lista de funções correspondentes
    AForm* (*constructors[])(const std::string&) = {
        &createShrubbery,
        &createRobotomy,
        &createPardon
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << names[i] << std::endl;
            return constructors[i](target); // chama a função correta
        }
    }

    std::cerr << "Intern couldn’t find the form: \"" << formName << "\"" << std::endl;
    return NULL;
}
