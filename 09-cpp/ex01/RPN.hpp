/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:22:51 by rsaueia           #+#    #+#             */
/*   Updated: 2025/11/15 14:31:41 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <stack>
#include <string>
#include <stdexcept>

/**
 * @brief Evaluates mathematical expressions written in Reverse Polish Notation (RPN).
 * 
 * Example:
 *   Input: "3 4 + 2 * 7 /"
 *   Output: ((3 + 4) * 2) / 7 = 2
 */
class RPN {
	
	private:
    std::stack<int> _stack;

    bool isOperator(char c) const;
    int applyOperator(char op, int a, int b) const;
	
	public:
    RPN();
    RPN(const RPN&);
    RPN& operator=(const RPN&);
    ~RPN();

    /**
     * @brief Evaluate the given RPN expression.
     * 
     * @param expr Expression string (tokens separated by spaces).
     * @return int The resulting integer value.
     * @throws std::runtime_error if the expression is invalid.
     */
    int evaluate(const std::string& expr);
};

