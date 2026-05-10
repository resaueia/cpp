/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:23:39 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/09/29 17:07:43 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat john("John", 2);
        Bureaucrat bill("Bill", 149);
        //Bureaucrat johnny(john);
        //Bureaucrat jon = john;
        std::cout << john << std::endl;
        std::cout << bill << std::endl;
        //std::cout << johnny << std::endl;
        //std::cout << jon << std::endl;

        john.incrementGrade(); // 2 → 1
        bill.decrementGrade();
        std::cout << john << std::endl;
        std::cout << bill << std::endl;

        john.incrementGrade(); // 1 → erro
        //bill.decrementGrade();
        std::cout << john << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

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
