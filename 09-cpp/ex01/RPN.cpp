/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:41:44 by rsaueia           #+#    #+#             */
/*   Updated: 2025/11/16 14:55:47 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <iostream>

RPN::RPN() {}
RPN::RPN(const RPN& rhs) { *this = rhs; }
RPN& RPN::operator=(const RPN& rhs) {
    (void)rhs;
    return *this;
}
RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::applyOperator(char op, int a, int b) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: division by zero");
            return a / b;
        default:
            throw std::runtime_error("Error: invalid operator");
    }
}

int RPN::evaluate(const std::string& expr) {
    // Reset stack in case evaluate() gets called multiple times 
    while (!_stack.empty())
        _stack.pop();

    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {

        // Case 1: token is exactly one character
        if (token.size() == 1) {
            char c = token[0];

            // If it's an operator => apply it
            if (isOperator(c)) {
                if (_stack.size() < 2)
                    throw std::runtime_error("Error");
                
                int b = _stack.top(); _stack.pop();
                int a = _stack.top(); _stack.pop();
                _stack.push(applyOperator(c, a, b));
                continue;
            }

            // If it's a single-digit number => push it
            if (std::isdigit(c)) {
                _stack.push(c - '0'); 
                continue;
            }

            // Single character, but not digit nor operator => invalid
            throw std::runtime_error("Error");
        }

        // Case 2: token has more than one character => invalid in this subject
        throw std::runtime_error("Error");
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}
