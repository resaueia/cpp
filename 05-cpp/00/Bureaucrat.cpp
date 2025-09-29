/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:45:29 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/09/29 17:04:08 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        // name is const, so we cannot reassign it!
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

/* GETTERS */

const std::string& Bureaucrat::getName() const{
    return (this->name);
}

int Bureaucrat::getGrade() const {
    return (this->grade);
}

/* MEMBER FUNCTIONS */

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "=O Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "=( Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}