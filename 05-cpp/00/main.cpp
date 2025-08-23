/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:23:39 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/08/23 16:38:12 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat john("John", 2);
        std::cout << john << std::endl;

        john.incrementGrade(); // 2 → 1
        std::cout << john << std::endl;

        john.incrementGrade(); // 1 → erro
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "----------" << std::endl;

    try {
        Bureaucrat jane("Jane", 150);
        std::cout << jane << std::endl;

        jane.decrementGrade(); // 150 → erro
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
