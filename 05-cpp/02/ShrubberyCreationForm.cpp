/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:59:33 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/09/30 16:57:21 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>


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
"               ,@@@@@@@,\n"
"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
"       |o|        | |         | |\n"
"       |.|        | |         | |\n"
"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";

    outFile.close();
}
