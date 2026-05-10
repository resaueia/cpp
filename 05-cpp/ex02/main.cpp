/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:27:16 by rsaueia           #+#    #+#             */
/*   Updated: 2025/09/28 14:27:32 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat renan("Renan", 1);             // Top authority
        Bureaucrat bob("Bob", 140);               // Fraco
        Bureaucrat susan("Susan", 45);            // Média

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Zaphod");

        std::cout << "\n--- Teste: SHRUBBERY FORM ---\n";
        bob.signForm(shrub);           // Deve conseguir assinar
        bob.executeForm(shrub);        // Não pode executar (grade muito baixa)
        renan.executeForm(shrub);      // Executa com sucesso (cria arquivo)

        std::cout << "\n--- Teste: ROBOTOMY FORM ---\n";
        renan.signForm(robot);         // Assina sem problemas
        susan.executeForm(robot);      // Deve conseguir executar (grade == 45)

        std::cout << "\n--- Teste: PARDON FORM ---\n";
        susan.signForm(pardon);        // Não consegue assinar (precisa de grade 25)
        renan.signForm(pardon);        // Consegue
        renan.executeForm(pardon);     // Executa com sucesso

    } catch (const std::exception& e) {
        std::cerr << "[ERRO GLOBAL] " << e.what() << std::endl;
    }

    return 0;
}
