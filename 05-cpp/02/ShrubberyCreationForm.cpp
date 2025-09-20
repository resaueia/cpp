/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:59:33 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/09/20 18:03:09 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

/* -------------------------------------------------------------------------- */
/*                               CONSTRUTOR                                   */
/* -------------------------------------------------------------------------- */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
        this->target = other.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    // 1. Checa se o form está assinado
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();

    // 2. Checa se o executor tem grade suficiente
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    // 3. Cria o arquivo <target>_shrubbery
    std::ofstream outFile((target + "_shrubbery").c_str());
    if (!outFile) {
        std::cerr << "Error: could not create file." << std::endl;
        return;
    }

    // 4. Escreve arte ASCII no arquivo
    outFile <<
        "       🌳\n"
        "      🌲🌲\n"
        "     🌳🌳🌳\n"
        "    🌲🌲🌲🌲\n"
        "   🌳🌳🌳🌳🌳\n"
        "      |||\n"
        "      |||\n";

    outFile.close();
}
