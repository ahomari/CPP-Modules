/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:14:59 by ahomari           #+#    #+#             */
/*   Updated: 2025/01/31 19:26:30 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
    private:
        int                                 unpaired;
        int                                 size;
        std::vector<int>                    jacobsthalNbr;
        std::vector<std::pair<int, int> >   vec;
        std::deque<std::pair<int, int> >    deq;
        
        PmergeMe();
        std::vector<int> mergeInsertionSort(std::vector<std::pair<int, int> >& vec);
        std::deque<int> mergeInsertionSort(std::deque<std::pair<int, int> >& dec);
        void generateJacobsthal(int size);
    public:
        PmergeMe(std::vector<int> dataNbr);
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();
        void sortNumbers(std::vector<int>& dataNbr);
        template <typename Container>
        void printContainer(const Container& container, const std::string& msg);
};

void loadDataNbr(char **av, std::vector<int>& dataNbr);
