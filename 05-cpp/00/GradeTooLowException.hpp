/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:52:35 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/07/24 15:55:19 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <exception>

class GradeTooLowException : std::exception
{
    public:
        const char* what() const throw() { return "Something went terribly wrong!"; }
};