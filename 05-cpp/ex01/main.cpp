/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 19:20:34 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/08/23 19:20:52 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Bureaucrats
    Bureaucrat alice("Alice", 50);   // grade mediano
    Bureaucrat bob("Bob", 1);        // grade máximo
    Bureaucrat tom("Tom", 150);      // grade mínimo

    // Forms
    Form f1("NDA", 100, 50);         // Fácil de assinar
    Form f2("Top Secret", 25, 10);   // Exige grade alto
    Form f3("Dismissal", 150, 150);  // Qualquer um pode assinar

    std::cout << "\n--- PRINTING FORMS ---\n";
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    std::cout << "\n--- SIGNING ATTEMPTS ---\n";

    alice.signForm(f1); // Deve funcionar
    tom.signForm(f1);   // Deve falhar
    bob.signForm(f2);   // Deve funcionar
    alice.signForm(f2); // Deve falhar

    std::cout << "\n--- AFTER SIGNATURES ---\n";
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    return 0;
}