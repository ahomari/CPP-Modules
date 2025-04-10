/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:47:41 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/10 19:47:32 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal *w = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "---------\n";
    i->makeSound(); //will output the cat sound!
    std::cout << "---------\n";
    j->makeSound();
    std::cout << "---------\n";
    meta->makeSound();
    std::cout << "---------\n";
    w->makeSound();
    delete w;
    delete j;
    delete i;
    delete meta;
    return 0;
}