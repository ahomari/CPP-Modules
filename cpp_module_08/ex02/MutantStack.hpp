/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:51:27 by ahomari           #+#    #+#             */
/*   Updated: 2025/01/09 11:18:41 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>
#include <list>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(){};
        ~MutantStack(){};
        MutantStack(const MutantStack& obj){
            this = obj;
        }
        MutantStack& operator=(const MutantStack& obj){
            if (this != &obj){
                std::stack<T>::operator=(obj);
            }
            return *this;
        }
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::reverse_iterator reverse_iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;

        iterator begin(){
            return this->c.begin();
        }
        iterator end(){
            return this->c.end();
        }
        reverse_iterator rbegin(){
            return this->c.rbegin();
        }
        reverse_iterator rend(){
            return this->c.rend();
        }
        const_iterator begin() const{
            return this->c.begin();
        }
        const_iterator end() const{
            return this->c.end();
        }
        
};
