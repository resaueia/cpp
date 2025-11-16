/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:41:44 by rsaueia           #+#    #+#             */
/*   Updated: 2025/11/16 14:41:47 by rsaueia          ###   ########.fr       */
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
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        // Single character token?
        if (token.size() == 1 && isOperator(token[0])) {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: not enough operands");

            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            int res = applyOperator(token[0], a, b);
            _stack.push(res);
        }
        else {
            // Expecting integer (can be multiple digits)
            for (size_t i = 0; i < token.size(); ++i)
                if (!std::isdigit(token[i]))
                    throw std::runtime_error("Error: invalid token");

            int value;
            std::istringstream(token) >> value;
            _stack.push(value);
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");

    return _stack.top();
}
