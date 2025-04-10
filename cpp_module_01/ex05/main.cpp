/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:10:25 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/18 12:13:20 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "=== DEBUG ===" << std::endl;
    harl.complain("DEBUG");

    std::cout << "=== INFO ===" << std::endl;
    harl.complain("INFO");

    std::cout << "=== WARNING ===" << std::endl;
    harl.complain("WARNING");

    std::cout << "=== ERROR ===" << std::endl;
    harl.complain("ERROR");

    return 0;
}