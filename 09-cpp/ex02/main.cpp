/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:00:00 by rsaueia           #+#    #+#             */
/*   Updated: 2025/11/17 10:00:00 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>

/*
 * PmergeMe – sorts a sequence of positive integers using the Ford-Johnson
 * (merge-insert sort) algorithm, executed independently on two STL containers:
 *   - std::vector<int>
 *   - std::deque<int>
 *
 * Output format:
 *   Before:  <unsorted sequence>
 *   After:   <sorted sequence>
 *   Time to process a range of N elements with std::vector : X us
 *   Time to process a range of N elements with std::deque  : Y us
 *
 * Usage: ./PmergeMe 3 5 9 7 4
 */
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: usage: ./PmergeMe <positive integer> [...]"
                  << std::endl;
        return 1;
    }

    try
    {
        PmergeMe sorter;
        sorter.parse(argc, argv);

        sorter.printBefore();

        sorter.sortVec();
        sorter.sortDeq();

        sorter.printAfterVec();

        std::size_t n = sorter.getSize();
        std::cout << "Time to process a range of "
                  << std::setw(6) << n
                  << " elements with std::vector : "
                  << std::fixed << std::setprecision(5)
                  << sorter.getVecTime() << " us" << std::endl;

        std::cout << "Time to process a range of "
                  << std::setw(6) << n
                  << " elements with std::deque  : "
                  << std::fixed << std::setprecision(5)
                  << sorter.getDeqTime() << " us" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
