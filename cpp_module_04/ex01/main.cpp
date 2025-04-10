/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:47:41 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/10 22:52:33 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main()
{
    int size = 4;
    Animal* Animals[size];
    
    int i = 0;
    while (i < size / 2){
        Animals[i] = new Dog();
        i++;
    }
    while (i < size)
    {
        Animals[i] = new Cat();
        i++;
    }
    i = 0;
    while (i < size){
        Animals[i]->makeSound();
        i++;
    }
    i = 0;
    while (i < size){
        delete Animals[i];
        i++;
    }
    
}