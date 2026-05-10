/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:13:29 by rsaueia           #+#    #+#             */
/*   Updated: 2025/09/28 14:16:40 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), target(other.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		this->target = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    // Verifica se está assinado
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();

    // Verifica se o Bureaucrat tem grade suficiente
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    // Ação principal do formulário
    std::cout << target << " was pardoned by Zaphod Beeblebrox." << std::endl;
}

