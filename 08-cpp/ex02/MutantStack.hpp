/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:05:18 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/10/26 14:53:55 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <stack>
# include <deque>
# include <iterator>
# include <iostream>

/*
std::stack is NOT a container per se, but a container adaptor,
meaning that it uses an underlying container to store the elements.
It grants a pile interface to the underlying container (by default
std::deque). Therefore you can perform operations only on the top
element of the stack (push, pop, top, size, empty).
To be able to iterate through the elements of the stack,
we need to access the underlying container.
The idea here is to inherit from std::stack and expose the iterators
of the underlying container.
*/

/*
namespace: meant to group names and avoid name collisions.
typedef: creates an alias for a type.
typename: tells the compiler that something inside a template is a type.
*/

/*
Since std::stack is not a container per ser, but a sort of interface,
we need to access its underlying container to be able to iterate through it.
The underlying container is a protected member called 'c'.
*/

template <typename T>

class MutantStack : public std::stack<T>
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
        ~MutantStack() {}

        //definitions
        
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        
        // implementations

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }

        reverse_iterator rbegin() { return this->c.rbegin(); }
        reverse_iterator rend() { return this->c.rend(); }
        const_reverse_iterator rbegin() const { return this->c.rbegin(); }
        const_reverse_iterator rend() const { return this->c.rend(); }
};