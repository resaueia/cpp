/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:29:29 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/19 16:01:49 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <iostream>
#include <iterator>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	numbers;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			if (numbers.size() + std::distance(begin, end) > _maxSize)
				throw std::runtime_error("The desired range exceeds the maximum size of the Span.");
			numbers.insert(numbers.end(), begin, end);
		}

		void printNumbers() const;
};