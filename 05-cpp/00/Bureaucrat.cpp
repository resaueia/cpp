/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:45:29 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/07/24 16:20:30 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(name), grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
    if (this != &other)
    {
        this->name = other.name;
        this->grade = other.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const{
    return (this->name);
}

int Bureaucrat::getGrade(){
    return (this->grade);
}