/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:19:30 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/18 15:46:21 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

// Simple print function
template<typename T>
void printElement(T const &x) {
    std::cout << x << " ";
}

// Example of a transformation function
void toUpper(std::string const &s) {
    std::string copy = s;
    for (size_t i = 0; i < copy.size(); i++)
        copy[i] = std::toupper(copy[i]);
    std::cout << copy << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"bonjour", "à", "tous"};

    std::cout << "Integers: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "Strings: ";
    iter(strArray, 3, toUpper);
    std::cout << std::endl;

    return 0;
}
