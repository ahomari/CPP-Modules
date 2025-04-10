/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:22:01 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/29 17:22:26 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

void    readFile(std::fstream& file, std::string& buff)
{
    std::string		line;
    while (std::getline(file, line)){
        buff += line;
        if (!file.eof()){
            buff += '\n';
        }
    }
}

void	writeFile(std::fstream& file, std::string buff, const std::string& s1, const std::string& s2)
{
	size_t index = 0;
	while (!s1.empty() && s1 != s2){
		index = buff.find(s1, index);
		if (index == std::string::npos)
			break ;
		buff.erase(index, s1.length());
		buff.insert(index, s2);
        index += s2.length();
	}
    file << buff;
}

int openFile(std::string& file, const std::string& s1, const std::string& s2)
{
    std::fstream	file1;
    std::fstream	file2;
	std::string		buff;
    file1.open(file, std::ios::in);
    if (!file1){
        std::cerr << "File could not be opened!" << std::endl;
        return (1);
    }
    file2.open(file + ".replace", std::ios::out | std::ios::trunc);
    if (!file2){
        std::cerr << "File could not be opened!" << std::endl;
        file1.close();
        return (1);
    }
    readFile(file1, buff);
	writeFile(file2, buff, s1, s2);
    file1.close();
    file2.close();
	return (0);
}
