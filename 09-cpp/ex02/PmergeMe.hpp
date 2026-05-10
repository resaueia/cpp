/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:00:00 by rsaueia           #+#    #+#             */
/*   Updated: 2025/11/17 10:00:00 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <stdexcept>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void        parse(int argc, char** argv);
    void        sortVec();
    void        sortDeq();

    void        printBefore() const;
    void        printAfterVec() const;
    void        printAfterDeq() const;

    double      getVecTime() const;
    double      getDeqTime() const;
    std::size_t getSize() const;

private:
    std::vector<int> _input;
    std::vector<int> _vec;
    std::deque<int>  _deq;
    double           _vecTime;
    double           _deqTime;
};

#endif
