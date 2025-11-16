/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:42:17 by rsaueia           #+#    #+#             */
/*   Updated: 2025/11/16 14:46:08 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

/**
 * @brief Entry point for the RPN evaluator.
 * 
 * Example:
 *   ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: invalid arguments." << std::endl;
		std::cerr << "Try something like: ./RPN 8 9 * 7 - 5 - 6 - 4 -1 +" << std::endl;
        return 1;
    }

    try {
        RPN calc;
        int result = calc.evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}


/*
In this exercise, the goal is to evaluate mathematical expressions written in
Reverse Polish Notation (RPN), where each number is pushed onto a stack and
operators act on the two most recent values.

To achieve this, the class `RPN` was created using a `std::stack<int>` container,
which is ideal for this task since it follows the LIFO (Last-In, First-Out) order.

Main methods:
 - evaluate()     → Parses the input string, pushes numbers, and applies operators.
 - applyOperator()→ Executes the mathematical operation between two integers.
 - isOperator()   → Checks if a character is one of '+', '-', '*', or '/'.

The user provides the RPN expression as a command-line argument, for example:
    ./RPN "3 4 + 2 * 7 /"

The program then calls `evaluate()` to process the expression and prints the
final calculated result to the standard output.
*/
