/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:22:15 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/18 12:29:06 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <limits.h>
#include <cstdio>

int openFile(std::string& file, const std::string& s1, const std::string& s2);
void	writeFile(std::fstream& file, std::string buff, const std::string& s1, const std::string& s2);
void    readFile(std::fstream& file, std::string& buff);

#endif