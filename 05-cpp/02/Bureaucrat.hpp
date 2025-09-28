/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:19:36 by rsaueia           #+#    #+#             */
/*   Updated: 2025/09/28 14:20:10 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm; // forward declaration para evitar include circular

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    // Constructors
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Grade modifiers
    void incrementGrade();
    void decrementGrade(); 

    // Form interactions
    void signForm(AForm& form) const;
    void executeForm(const AForm& form) const;

    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

// Output operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
