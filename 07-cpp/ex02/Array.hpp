/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:32:55 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/10/14 17:28:01 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
    private:
        unsigned int _size;
        T *arr;
    public:
        Array() : _size(0), arr(NULL) {};
        Array(unsigned int n) : _size(n), arr(new T[n]()) {};
        Array(const Array &other) : _size(other._size), arr(new T[other._size]) {
            for (unsigned int i = 0; i < _size; i++) {
                arr[i] = other.arr[i];
            }
        };
        Array &operator=(const Array &other) {
            if (this != &other) {
                delete[] arr;
                _size = other._size;
                arr = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    arr[i] = other.arr[i];
                }
            }
            return *this;
        };
         ~Array() { delete[] arr;};


        T &operator[](unsigned int index) {
            if (index >= _size)
                throw std::out_of_range("Index is out of range!");
            return arr[index];
        };

        const T &operator[](unsigned int index) const {
            if (index >= _size)
                throw std::out_of_range("Index is out of range!");
            return arr[index];
    }


        unsigned int size() const { return _size; };
};