/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:48:16 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/07/24 15:55:37 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <exception>

class GradeTooHighException : public std::exception
{
    public:
        const char* what() const throw() { return "Something went terribly wrong!"; }
};