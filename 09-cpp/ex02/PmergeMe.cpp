/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:00:00 by rsaueia           #+#    #+#             */
/*   Updated: 2025/11/17 10:00:00 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>
#include <sys/time.h>

/* ─── Helpers ─────────────────────────────────────────────────────────────── */

/*
 * buildInsertionOrder – returns 1-indexed positions of b_2..b_m
 * in the Jacobsthal-optimal order.
 *
 * Jacobsthal: J(0)=0, J(1)=1, J(2)=3, J(3)=5, J(4)=11, J(5)=21, …
 * Insertion groups are formed by descending from J(k) to J(k-1)+1.
 * This keeps each binary search range as small as possible.
 */
static std::vector<std::size_t> buildInsertionOrder(std::size_t m)
{
    std::vector<std::size_t> order;
    if (m <= 1)
        return order;

    std::vector<std::size_t> J;
    J.push_back(1);
    J.push_back(3);
    while (J.back() < m)
    {
        std::size_t sz = J.size();
        J.push_back(J[sz - 1] + 2 * J[sz - 2]);
    }

    std::size_t prevJ = 1;
    for (std::size_t k = 1; k < J.size(); ++k)
    {
        std::size_t curJ = (J[k] < m) ? J[k] : m;
        for (std::size_t i = curJ; i > prevJ; --i)
            order.push_back(i); /* 1-indexed */
        prevJ = J[k];
        if (J[k] >= m)
            break;
    }
    return order;
}

/*
 * fordJohnsonVec – Ford-Johnson (merge-insert) sort on std::vector<int>.
 *
 * Steps at each recursive level:
 *  1. Save straggler if n is odd.
 *  2. Form pairs (larger, smaller).
 *  3. Extract larger values, sort them recursively with the same algorithm.
 *  4. Re-associate each sorted larger value with its smaller partner.
 *  5. Build main chain: [b_1, a_1, a_2, …, a_m].
 *  6. Insert b_2..b_m into the chain using Jacobsthal order + binary search,
 *     with each search bounded above by the position of a_k (since b_k ≤ a_k).
 *  7. Insert straggler at its correct position.
 */
static void fordJohnsonVec(std::vector<int>& arr)
{
    std::size_t n = arr.size();
    if (n <= 1)
        return;

    bool odd = (n % 2 != 0);
    int  straggler = odd ? arr.back() : 0;
    if (odd) { arr.pop_back(); --n; }

    /* Step 2: pair adjacent elements, larger first */
    std::vector<std::pair<int, int> > pairs;
    for (std::size_t i = 0; i < n; i += 2)
    {
        int a = arr[i], b = arr[i + 1];
        if (a < b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    /* Step 3: recursively sort the larger elements */
    std::size_t m = pairs.size();
    std::vector<int> firsts;
    for (std::size_t i = 0; i < m; ++i)
        firsts.push_back(pairs[i].first);
    fordJohnsonVec(firsts);

    /* Step 4: re-associate pairs with sorted larger values
     *  firsts[i] is the i-th sorted larger value; find the first unused
     *  original pair whose .first matches and move it to sortedPairs[i]. */
    std::vector<bool>              used(m, false);
    std::vector<std::pair<int,int> > sortedPairs;
    for (std::size_t i = 0; i < m; ++i)
    {
        for (std::size_t j = 0; j < m; ++j)
        {
            if (!used[j] && pairs[j].first == firsts[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }
    pairs = sortedPairs;

    /* Step 5: build main chain [b_1, a_1, a_2, …, a_m] */
    std::vector<int> chain;
    chain.push_back(pairs[0].second);
    for (std::size_t i = 0; i < m; ++i)
        chain.push_back(pairs[i].first);

    /* Step 6: insert b_2..b_m in Jacobsthal order */
    std::vector<std::size_t> order = buildInsertionOrder(m);
    for (std::size_t i = 0; i < order.size(); ++i)
    {
        std::size_t idx  = order[i] - 1; /* 0-indexed */
        int         bVal = pairs[idx].second;
        int         aVal = pairs[idx].first;

        /* upper bound of binary search: position of a_k (since b_k ≤ a_k) */
        std::vector<int>::iterator aIt  =
            std::lower_bound(chain.begin(), chain.end(), aVal);
        std::vector<int>::iterator pos  =
            std::lower_bound(chain.begin(), aIt + 1, bVal);
        chain.insert(pos, bVal);
    }

    /* Step 7: re-insert straggler */
    if (odd)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }

    arr = chain;
}

/*
 * fordJohnsonDeq – same algorithm as fordJohnsonVec but for std::deque<int>.
 * The internal pairs use std::deque<std::pair<int,int>> so the second
 * container is used consistently throughout.
 */
static void fordJohnsonDeq(std::deque<int>& arr)
{
    std::size_t n = arr.size();
    if (n <= 1)
        return;

    bool odd = (n % 2 != 0);
    int  straggler = odd ? arr.back() : 0;
    if (odd) { arr.pop_back(); --n; }

    std::deque<std::pair<int, int> > pairs;
    for (std::size_t i = 0; i < n; i += 2)
    {
        int a = arr[i], b = arr[i + 1];
        if (a < b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::size_t m = pairs.size();
    std::deque<int> firsts;
    for (std::size_t i = 0; i < m; ++i)
        firsts.push_back(pairs[i].first);
    fordJohnsonDeq(firsts);

    std::vector<bool>                used(m, false);
    std::deque<std::pair<int, int> > sortedPairs;
    for (std::size_t i = 0; i < m; ++i)
    {
        for (std::size_t j = 0; j < m; ++j)
        {
            if (!used[j] && pairs[j].first == firsts[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }
    pairs = sortedPairs;

    std::deque<int> chain;
    chain.push_back(pairs[0].second);
    for (std::size_t i = 0; i < m; ++i)
        chain.push_back(pairs[i].first);

    std::vector<std::size_t> order = buildInsertionOrder(m);
    for (std::size_t i = 0; i < order.size(); ++i)
    {
        std::size_t idx  = order[i] - 1;
        int         bVal = pairs[idx].second;
        int         aVal = pairs[idx].first;

        std::deque<int>::iterator aIt =
            std::lower_bound(chain.begin(), chain.end(), aVal);
        std::deque<int>::iterator pos =
            std::lower_bound(chain.begin(), aIt + 1, bVal);
        chain.insert(pos, bVal);
    }

    if (odd)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }

    arr = chain;
}

/* ─── PmergeMe ─────────────────────────────────────────────────────────────── */

PmergeMe::PmergeMe() : _vecTime(0.0), _deqTime(0.0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _input(other._input),
      _vec(other._vec),
      _deq(other._deq),
      _vecTime(other._vecTime),
      _deqTime(other._deqTime) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _input   = other._input;
        _vec     = other._vec;
        _deq     = other._deq;
        _vecTime = other._vecTime;
        _deqTime = other._deqTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parse(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int val;
        char extra;
        if (!(iss >> val) || iss >> extra)
            throw std::runtime_error("Error: invalid token: " + std::string(argv[i]));
        if (val <= 0)
            throw std::runtime_error("Error: only positive integers are allowed.");
        _input.push_back(val);
    }
    if (_input.empty())
        throw std::runtime_error("Error: no input provided.");
}

void PmergeMe::sortVec()
{
    _vec.assign(_input.begin(), _input.end());

    struct timeval start, end;
    gettimeofday(&start, NULL);

    fordJohnsonVec(_vec);

    gettimeofday(&end, NULL);
    _vecTime = static_cast<double>(end.tv_sec  - start.tv_sec)  * 1e6
             + static_cast<double>(end.tv_usec - start.tv_usec);
}

void PmergeMe::sortDeq()
{
    _deq.assign(_input.begin(), _input.end());

    struct timeval start, end;
    gettimeofday(&start, NULL);

    fordJohnsonDeq(_deq);

    gettimeofday(&end, NULL);
    _deqTime = static_cast<double>(end.tv_sec  - start.tv_sec)  * 1e6
             + static_cast<double>(end.tv_usec - start.tv_usec);
}

void PmergeMe::printBefore() const
{
    std::cout << "Before:";
    for (std::size_t i = 0; i < _input.size(); ++i)
        std::cout << " " << _input[i];
    std::cout << std::endl;
}

void PmergeMe::printAfterVec() const
{
    std::cout << "After: ";
    for (std::size_t i = 0; i < _vec.size(); ++i)
        std::cout << " " << _vec[i];
    std::cout << std::endl;
}

void PmergeMe::printAfterDeq() const
{
    std::cout << "After: ";
    for (std::size_t i = 0; i < _deq.size(); ++i)
        std::cout << " " << _deq[i];
    std::cout << std::endl;
}

double PmergeMe::getVecTime() const { return _vecTime; }
double PmergeMe::getDeqTime() const { return _deqTime; }

std::size_t PmergeMe::getSize() const { return _input.size(); }
