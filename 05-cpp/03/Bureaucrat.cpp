/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:20:37 by rsaueia           #+#    #+#             */
/*   Updated: 2025/09/28 14:20:39 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* -------------------- Constructors / Destructor -------------------- */

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

/* -------------------------- Getters -------------------------- */

const std::string& Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

/* --------------------- Grade Modification --------------------- */

void Bureaucrat::incrementGrade() {
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

/* ------------------------ Interações com Form ------------------------ */

void Bureaucrat::signForm(AForm& form) const {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << name << " couldn’t sign " << form.getName()
                  << " because: " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << name << " couldn’t execute " << form.getName()
                  << " because: " << e.what() << std::endl;
    }
}

/* ------------------------ Exceptions ------------------------ */

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat Exception: Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat Exception: Grade too low";
}

/* ----------------------- Output overload ----------------------- */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
