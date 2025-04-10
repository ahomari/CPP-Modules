/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:40:44 by ahomari           #+#    #+#             */
/*   Updated: 2025/01/09 09:21:53 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
}

Span::Span(const unsigned int n)
{
    N = n;
}

Span::Span(const Span &obj)
{
    N = obj.N;
    numbers = obj.numbers;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &obj)
{
    if (this != &obj){
        N = obj.N;
        numbers = obj.numbers;
    }
    return *this;
}

unsigned int Span::getSize() const
{
    return N;
}

void Span::addNumber(const int nbr)
{
    if (numbers.size() >= getSize()){
        throw std::runtime_error("Cannot add more numbers, Span is full");
    }
    numbers.push_back(nbr);
}

void Span::addNumber(std::vector<int> vec)
{
    numbers.insert(numbers.begin(), vec.begin(), vec.end());
}

void Span::addRandomNumbers(std::vector<int>&vec)
{
    srand(time(NULL));
    for (unsigned int i = 0; i < getSize(); i++){    
        if (vec.size() >= getSize()){
            throw std::runtime_error("Cannot add more numbers, Span is full");
        }
        int nbr = (rand() % 20000);
        vec.push_back(nbr);
    }
}

void Span::printVector(std::vector<int> vec)
{
    for (std::vector<int>::iterator it = vec.begin() + 1; it != vec.end(); it++) {
        std::cout << "Value = " << *it << std::endl;;
    }
}

void Span::printVector(void)
{
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << "Value = " << *it << std::endl;;
    }
}

void Span::print(void)
{
    
}

int Span::longestSpan()
{
    if (numbers.size() < 2){
        throw std::runtime_error("Not enough numbers to calculate a span");
    }
    int max = *std::max_element(numbers.begin(), numbers.end());
    int min = *std::min_element(numbers.begin(), numbers.end());
    return max - min;
}

int Span::shortestSpan()
{
    if (numbers.size() < 2){
        throw std::runtime_error("Not enough numbers to calculate a span");
    }
    int min = std::numeric_limits<int>::max();
    std::vector<int> tmp = numbers;
    sort(tmp.begin(), tmp.end());
    for (std::vector<int>::iterator it = tmp.begin() + 1; it != tmp.end(); it++){
        if (min > (*it - *(it - 1))){
            min = *it - *(it - 1);
        }
    }
    return min;
}


