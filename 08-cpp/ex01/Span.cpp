/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:38:43 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/19 16:01:59 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), numbers(other.numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		numbers = other.numbers;
	}
	return *this;
}

Span::~Span() {}

/*  METHODS  */

void Span::addNumber(int number)
{
	if (numbers.size() >= _maxSize)
		throw std::runtime_error("Cannot add more numbers, Span is full.");
	numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    std::vector<int> sorted = numbers;  // copy to avoid modifying the original!!!
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 0; i < sorted.size() - 1; ++i)
    {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	int minNum = *std::min_element(numbers.begin(), numbers.end());
	int maxNum = *std::max_element(numbers.begin(), numbers.end());

	return maxNum - minNum;
}

void Span::printNumbers() const
{
    std::cout << "[ ";
    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it)
        std::cout << *it << " ";
    std::cout << "]" << std::endl;
}