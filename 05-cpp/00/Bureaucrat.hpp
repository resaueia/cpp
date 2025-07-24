/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:46:25 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/07/24 16:10:14 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <stdio.h>
#include <string>
#include <stdexcept>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();

        const std::string& getName() const;
        int getGrade();

        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw() { return "Error. Grade detected is too high! :-(";}
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw() { return "Error. Grade detected is too low! :-(";}
        };
};