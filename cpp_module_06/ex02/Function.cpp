/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Function.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:57:52 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/28 09:37:06 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Function.hpp"

static Base *creatA()
{
    return new A();
}
static Base *creatB()
{
    return new B();
}
static Base *creatC()
{
    return new C();
}

Base *generate(void)
{
    Base* (*creatNew[])() = {creatA, creatB, creatC};
    srand(time(NULL));
    int random = rand() % 3;
    return creatNew[random]();
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p)){
        std::cout << "A" << std::endl;
    }else if (dynamic_cast<B*>(p)){
        std::cout << "B" << std::endl;
    }else if (dynamic_cast<C*>(p)){
        std::cout << "C" << std::endl;
    }
}

void identify(Base &p)
{
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::bad_cast &e){
        std::cerr << e.what() << std::endl;
    }
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::bad_cast &e){
        std::cerr << e.what() << std::endl;
    }
    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::bad_cast &e){
        std::cerr << e.what() << std::endl;
    }
}
