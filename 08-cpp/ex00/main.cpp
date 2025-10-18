/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:41:25 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/18 17:42:40 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

/**
 * @brief Test function for easyfind template
 * 
 * This function tests the easyfind() template function
 * using both std::vector and std::list containers.
 */
int main(void)
{
    try
    {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(15);
        lst.push_back(25);

        std::cout << "Searching 20 in vector..." << std::endl;
        std::vector<int>::iterator it1 = easyfind(vec, 20);
        std::cout << "Found: " << *it1 << std::endl;

        std::cout << "Searching 25 in list..." << std::endl;
        std::list<int>::iterator it2 = easyfind(lst, 25);
        std::cout << "Found: " << *it2 << std::endl;

        std::cout << "Searching 100 in vector..." << std::endl;
        easyfind(vec, 100); // should throw exception!
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
