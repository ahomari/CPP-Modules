/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:15:06 by ahomari           #+#    #+#             */
/*   Updated: 2025/01/31 19:25:39 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    *this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj){
        unpaired = obj.unpaired;
        size = obj.size;
        vec.assign(obj.vec.begin(), obj.vec.end());
        deq.assign(obj.deq.begin(), obj.deq.end());
        jacobsthalNbr.assign(obj.jacobsthalNbr.begin(), obj.jacobsthalNbr.end());
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
    vec.clear();
    deq.clear();
    jacobsthalNbr.clear();
}

PmergeMe::PmergeMe(std::vector<int> dataNbr)
{
    unpaired = -1;
    if (dataNbr.size() <= 1){
        throw std::runtime_error("Error: dataNbr must contain more than one element.");
    }
    if (dataNbr.size() % 2 != 0){
        unpaired = dataNbr.back();
        dataNbr.pop_back();
    }
    for(size_t i = 0; i < dataNbr.size(); i += 2){
        vec.push_back(std::make_pair(dataNbr[i], dataNbr[i + 1]));
        deq.push_back(std::make_pair(dataNbr[i], dataNbr[i + 1]));
    }
    size = static_cast<int>(vec.size());
    generateJacobsthal(size);
}

static bool checkFloat(std::string& str)
{
    for (size_t i = 0; i < str.length(); i++){
        char c = str[i];
        if (!isdigit(c)){
            return false;
        }
    }
    return true;
}

void loadDataNbr(char **av, std::vector<int>& dataNbr)
{
    char        *res;
    double      nbr;
    std::string str;
    
    for (int i = 1; av && av[i]; i++){
        str = av[i];
        if (str.length() == 0 || !checkFloat(str)){
            throw std::runtime_error("Error: Invalid argument!!");
        }
        nbr = strtod(av[i], &res);
        if (nbr > std::numeric_limits<int>::max()){
            throw std::runtime_error("Error: The number exceeds the maximum value for an int");
        }
        else if (nbr < 0){
            throw std::runtime_error("Error: Error: Negative numbers are not allowed");
        }
        else if (res[0] != '\0'){
            throw std::runtime_error("Error: Invalid argument!!");
        }
        dataNbr.push_back(nbr); 
    }
}


static std::vector<int> generateNumber(int n)
{
    std::vector<int>    jacobsthal;
    int                 nbr = 0;
    int                 i = 2;
    
    if (n >= 0)
        jacobsthal.push_back(0); 
    if (n >= 1)
        jacobsthal.push_back(1); 
    while (1337) {
        nbr = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        jacobsthal.push_back(nbr);
        if (n < nbr){
            break ;
        }
        i++;
    }
    return jacobsthal;
}
void PmergeMe::generateJacobsthal(int size)
{
    jacobsthalNbr = generateNumber(size);
    for(int i = 0; i <= size; i++)
    {
        if (std::find(jacobsthalNbr.begin(), jacobsthalNbr.end(), i) == jacobsthalNbr.end()){   
            std::vector<int>::iterator it = jacobsthalNbr.begin();
            for (; it != jacobsthalNbr.end(); it++)
            {
                if (i < *it){
                    jacobsthalNbr.insert(it + 1, i);
                    break ;
                }
            }
        }
    }
    jacobsthalNbr.erase(std::find(jacobsthalNbr.begin(), jacobsthalNbr.end(), 1));
}

void PmergeMe::sortNumbers(std::vector<int>& dataNbr)
{
    std::vector<int>    v;
    std::deque<int>     d;
    
    printContainer(dataNbr, "Before");
    clock_t startVec = clock();
    v = mergeInsertionSort(vec);
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec);
    
    clock_t startDeq = clock();
    d = mergeInsertionSort(deq);
    clock_t endDeq = clock();
    double timeDeq = static_cast<double>(endDeq - startDeq);

    printContainer(v, "After");
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " << std::fixed << (timeDeq / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;
    std::cout << "Time to process a range of " << v.size() << " elements with std::veclor : " << std::fixed << (timeVec / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;

}
std::vector<int> PmergeMe::mergeInsertionSort(std::vector<std::pair<int, int> > &vec)
{
    std::vector<int>            mainChain;
    std::vector<int>            pendChain;
    std::vector<int>::iterator  pos;
    
    mainChain.reserve((size / 2) + 1);
    pendChain.reserve(size / 2);
    for (size_t i = 0; i < vec.size(); i++){
        if (vec[i].first < vec[i].second){
            std::swap(vec[i].first, vec[i].second);
        }
    }
    for (size_t i = 1; i < vec.size(); i++){
        for (size_t j = i; j > 0 ; j--){
            if (vec[j].first < vec[j - 1].first){
                std::swap(vec[j], vec[j - 1]);
            }
        }
    }
    for (size_t i = 0; i < vec.size(); i++){
        mainChain.push_back(vec[i].first);
        pendChain.push_back(vec[i].second);
    }
    mainChain.insert(mainChain.begin(), pendChain[0]);
    for (size_t i = 1; i < jacobsthalNbr.size(); i++){
        if (jacobsthalNbr[i] < static_cast<int>(pendChain.size())){
            int value = pendChain[jacobsthalNbr[i]];
            pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
            mainChain.insert(pos, value);
        }
    }
    if (unpaired != -1){
        pos = std::lower_bound(mainChain.begin(), mainChain.end(), unpaired);
        mainChain.insert(pos, unpaired);
    }
    return mainChain;
}

std::deque<int> PmergeMe::mergeInsertionSort(std::deque<std::pair<int, int> > &deq)
{
    std::deque<int>             mainChain;
    std::deque<int>             pendChain;
    std::deque<int>::iterator   pos;

    for (size_t i = 0; i < deq.size(); i++){
        if (deq[i].first < deq[i].second){
            std::swap(deq[i].first, deq[i].second);
        }
    }
    for (size_t i = 1; i < deq.size(); i++){
        for (size_t j = i; j > 0 ; j--){
            if (deq[j].first < deq[j - 1].first){
                std::swap(deq[j], deq[j - 1]);
            }
        }
    }
    for (size_t i = 0; i < deq.size(); i++){
        mainChain.push_back(deq[i].first);
        pendChain.push_back(deq[i].second);
    }
    mainChain.insert(mainChain.begin(), pendChain[0]);
    for (size_t i = 1; i < jacobsthalNbr.size(); i++){
        if (jacobsthalNbr[i] < static_cast<int>(pendChain.size())){
            int value = pendChain[jacobsthalNbr[i]];
            pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
            mainChain.insert(pos, value);
        }
    }
    if (unpaired != -1){
        pos = std::lower_bound(mainChain.begin(), mainChain.end(), unpaired);
        mainChain.insert(pos, unpaired);
    }
    return mainChain;
}

template <typename Container>
void PmergeMe::printContainer(const Container &container, const std::string &msg)
{
    std::cout << msg << ": ";
    typename Container::const_iterator it = container.begin();
    for (; it != container.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
