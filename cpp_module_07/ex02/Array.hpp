/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:54:06 by ahomari           #+#    #+#             */
/*   Updated: 2025/01/04 11:42:25 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T>
class Array
{
    private:
        T* array;
        unsigned int len;
    public:
        Array()
        {
            len = 0;
            array = new T[len];
        }
        Array(unsigned int n)
        {
            len = n;
            array = new T[len];
            for(unsigned int i = 0; i < len; i++){
                array[i] = 0;
            }
        }
        Array(const Array& obj){
            len = obj.len;
            array = new T[len];
            for(unsigned int i = 0; i < len; i++){
                array[i] = obj.array[i];
            }
        }
        ~Array(){
            delete[] array;
        }
        Array& operator=(const Array& obj){
            if (this != &obj){
                len = obj.len;
                delete array;
                array = new T[len];
                for(unsigned int i = 0; i < len; i++){
                    array[i] = obj.array[i];
                }
            }
            return *this;
        }
        T& operator[](unsigned int index)
        {
            if (index >= len){
                throw std::exception();
            }
            return array[index];
        }
        unsigned int size(){
            return len;
        }
    
};