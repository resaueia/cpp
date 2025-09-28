/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:14:59 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/09/28 14:31:18 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>    // rand, srand
#include <ctime>      // time (para seed do rand)
#include <iostream>   


RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other)
        this->target = other.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    // Verifica se está assinado
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();

    // Verifica se grade do executor é suficiente
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    // Sons de perfuração
    std::cout << "* DRRRRRR DRRRRRRRRR *" << std::endl;

    // Semente para aleatoriedade (opcional, mas boa prática)
    std::srand(std::time(NULL));

    // Sorteia 0 ou 1
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "..." << std::endl;
}
