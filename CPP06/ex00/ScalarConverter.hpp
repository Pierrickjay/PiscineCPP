/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:37:20 by pjay              #+#    #+#             */
/*   Updated: 2023/06/15 09:18:06 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdlib>
#include "color.hpp"
#include <limits.h>


enum type
{
	INT = 0,
	CHAR,
	FLOAT,
	DOUBLE,
	UNEXIST
};

class ScalarConverter
{
	public :
		ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		~ScalarConverter();
		static void	convert(std::string toConvert);
		static int		findType(std::string toConvert);
};

/*Deal with Int*/
void	printInt(std::string s1);
void	intToChar(std::string s1);
void	intToFloat(std::string s1);
void	intToDouble(std::string s1);

/*Deal with Char*/
void	printChar(std::string s1);
void	charToFloat(std::string s1);
void	charToDouble(std::string s1);
void	charToInt(std::string s1);

/*Deal with double*/
void	printDouble(std::string s1);
void	doubleToChar(std::string s1);
void	doubleToFloat(std::string s1);
void	doubleToInt(std::string s1);

/*deal with float*/
void	printFloat(std::string s1);
void	floatToChar(std::string s1);
void	floatToInt(std::string s1);
void	floatToDouble(std::string s1);

void	printUnexist(void);

