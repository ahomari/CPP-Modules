/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:33:18 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/25 18:16:23 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    (void)obj;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    (void)obj;
    return *this;
}

static bool isInteger(const std::string& value){
    int flag = 0;
    for (size_t i = 0; i < value.length(); i++){
        if (i == 0 && (value[i] == '-' || value[i] == '+')){
            i++;
        }
        if (value[i] == '.'){
            flag++;
        }
        if (!isdigit(value[i]) && value[i] != '.') {
            return false;
        }
    }
    if (flag > 1)
        return false;
    return true;
}

static int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static void convertValue(double value)
{
    if (value < CHAR_MIN || value > CHAR_MAX || value != value){
        std::cout << "char: impossible" << std::endl;
    }
    else if (!ft_isprint(static_cast<char>(value))){
        std::cout << "char: Non displayable" << std::endl;
    }
    else{
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
    if (value < INT_MIN || value > INT_MAX || value != value){
        std::cout << "int: impossible" << std::endl;
    }
    else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}
static void convertChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    char *res = NULL;
    double value = strtod(str.c_str(), &res);
    if (str.length() == 1 && ft_isprint(str[0]) && !ft_isdigit(str[0])){
        char c = res[0];
        convertChar(c);
    }else if ((strlen(res) == 1 && res[0] == 'f') || isInteger(str) == true){
        convertValue(value);
    }else{
        double d;
        if (str == "nan" || str == "nanf"){
            d = std::numeric_limits<double>::quiet_NaN();
            convertValue(d);
        }else if (str == "-inf" || str == "-inff"){
            d = -std::numeric_limits<double>::infinity();
            convertValue(d);
        }else if (str == "inf" || str == "inff"){
            d = std::numeric_limits<double>::infinity();
            convertValue(d);
        }else{
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
    }
}

