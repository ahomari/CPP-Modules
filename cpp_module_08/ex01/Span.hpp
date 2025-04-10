/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:34:17 by ahomari           #+#    #+#             */
/*   Updated: 2025/01/09 09:20:38 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <limits>


class Span
{
    private:
        unsigned int N;
        std::vector<int> numbers;
        Span();
    public:
        Span(const unsigned int n);
        Span(const Span& obj);
        ~Span();
        Span& operator=(const Span& obj);
        unsigned int getSize() const;
        void addNumber(const int nbr);
        void addNumber(std::vector<int> vec);
        void addRandomNumbers(std::vector<int>& vec);
        void printVector(std::vector<int> vec);
        void printVector(void);
        void print(void);
        int longestSpan();
        int shortestSpan();
};