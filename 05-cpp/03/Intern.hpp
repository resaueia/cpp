/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:07:16 by rsaueia           #+#    #+#             */
/*   Updated: 2025/09/28 15:07:33 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    // Método principal: cria um formulário com base no nome passado
    AForm* makeForm(const std::string& formName, const std::string& target) const;
};