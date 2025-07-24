/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:30:04 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/07/24 15:32:40 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

int main(){
    try {
        std::cout << "Trying something..." << std::endl;
        throw std::runtime_error("Boom");
        std::cout << "You will never see this line." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}