/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:20:51 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/10/14 17:28:58 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>

int main() {
    try {
        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.size(); i++)
            numbers[i] = i * 2;

        std::cout << "Integer array: ";
        for (unsigned int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;

        Array<std::string> words(3);
        words[0] = "Hello";
        words[1] = "C++";
        words[2] = "Templates";

        std::cout << "String array: ";
        for (unsigned int i = 0; i < words.size(); i++)
            std::cout << words[i] << " ";
        std::cout << std::endl;

        // Deep copy test
        Array<std::string> copy = words;
        copy[1] = "World";

        std::cout << "Original: " << words[1] << " | Copy: " << copy[1] << std::endl;

        // Exception test
        std::cout << numbers[10] << std::endl; // invalid access

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
