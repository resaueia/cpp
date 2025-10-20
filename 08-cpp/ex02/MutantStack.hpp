/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:05:18 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/10/20 18:02:17 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <stack>
# include <deque>
# include <iterator>
# include <iostream>


template <typename T>

class MutantStack : public td::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack &other) : std::stack<T>(other) {}
        MutantStack &operator=(const MutantStack &other)
        {
            if (this != &other)
            {
                std::stack<T>::operator=(other);
                return *this;
            }   
        }
}