/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:00:00 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/19 16:00:11 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main(void)
{
    try
    {
        std::cout << "=== Basic tests ===" << std::endl;
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        sp.printNumbers();

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::cout << "\n=== Range insertion test ===" << std::endl;
        std::vector<int> v;
        for (int i = 0; i < 10000; ++i)
            v.push_back(i);

        Span big(20000);
        big.addRange(v.begin(), v.end());
        big.addRange(v.begin(), v.begin() + 5000);

        std::cout << "Shortest span (big): " << big.shortestSpan() << std::endl;
        std::cout << "Longest span (big): " << big.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
