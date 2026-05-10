/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:10:04 by rsaueia           #+#    #+#             */
/*   Updated: 2025/09/28 15:11:12 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;

    std::cout << "\n--- Teste: Shrubbery Creation ---\n";
    AForm* shrub = intern.makeForm("shrubbery creation", "garden");
    if (shrub) {
        Bureaucrat bob("Bob", 130); // suficiente para assinar e executar
        bob.signForm(*shrub);
        bob.executeForm(*shrub);
        delete shrub;
    }

    std::cout << "\n--- Teste: Robotomy Request ---\n";
    AForm* robot = intern.makeForm("robotomy request", "Bender");
    if (robot) {
        Bureaucrat susan("Susan", 40); // suficiente
        susan.signForm(*robot);
        susan.executeForm(*robot);
        delete robot;
    }

    std::cout << "\n--- Teste: Presidential Pardon ---\n";
    AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
    if (pardon) {
        Bureaucrat renan("Renan", 1); // top rank
        renan.signForm(*pardon);
        renan.executeForm(*pardon);
        delete pardon;
    }

    std::cout << "\n--- Teste: Formulário inexistente ---\n";
    AForm* unknown = intern.makeForm("vacation request", "Marvin");
    if (!unknown)
        std::cout << "Retorno corretamente foi NULL.\n";

    return 0;
}
