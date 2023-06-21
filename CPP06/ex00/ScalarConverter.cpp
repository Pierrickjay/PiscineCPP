/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:38:00 by pjay              #+#    #+#             */
/*   Updated: 2023/06/21 09:50:56 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << BLUE "Constructor of ScalarConverter called" RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
	(void)rhs;
	std::cout << BLUE "Constructor by assignement of ScalarConverter called" RESET << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void)rhs;
	std::cout << BLUE "operator= of ScalarConverter called" RESET << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << BLUE "destructor of ScalarConverter called" RESET << std::endl;
}

int		ScalarConverter::findType(std::string toConvert)
{
	bool		intChecker = true;
	bool		doubleChecker = true;
	bool		point = false;
	bool		floatChecker = true;
	long int	intbig;
	float		doublebig;
	char		*endPtr;

	if (toConvert.length() == 0)
		return UNEXIST;
	for (size_t i = 0; i < toConvert.length(); i++)
	{
		if (!isdigit(toConvert[i]))
		{
			if (toConvert[i] != '-' && toConvert[i] != '+')
				intChecker = false;
			if (toConvert[i] == '.')
			{
				if (point == true)
					return UNEXIST;
				point = true;
			}
			if ((i != 0 && (toConvert[i] == '-' || toConvert[i] == '+')))
				return UNEXIST;
			else if (toConvert[i] != '.')
			{
				if (toConvert[i] != '-' && toConvert[i] != '+')
				{
					doubleChecker = false;
					if ((toConvert[i] != 'f' && toConvert[i] != 'F') || i + 1 != toConvert.length())
						floatChecker = false;
				}
			}
		}
	}
	if (intChecker == true)
	{
		intbig = std::strtol(toConvert.c_str(), &endPtr, 10);
		if (intbig > INT_MAX || intbig < INT_MIN || *endPtr != '\0')
			return UNEXIST;
	}
	else if (doubleChecker == true)
	{
		doublebig = std::strtod(toConvert.c_str(), &endPtr);
		if (*endPtr != '\0')
			return UNEXIST;
	}
	return intChecker ? INT : doubleChecker ? DOUBLE : floatChecker ? FLOAT : toConvert.length() > 1 ? UNEXIST : CHAR;
}

void	ScalarConverter::convert(std::string toConvert)
{
	int type;

	type = findType(toConvert);
	if (type == UNEXIST)
	{
		printUnexist(toConvert);
		return ;
	}
	else if (type == INT)
	{
		printInt(toConvert);
		return;
	}
	else if (type == CHAR)
		printChar(toConvert);
	else if (type == FLOAT)
		printFloat(toConvert);
	else if (type == DOUBLE)
		printDouble(toConvert);
}

void printUnexist(std::string toConvert)
{
	if (toConvert == "-inff" || toConvert == "+inff" || toConvert == "nanf")
	{
		std::cout << YELLOW "=========================================" RESET << std::endl;
		std::cout <<  BLUE"       Char: Non displayable" RESET<< std::endl;
		std::cout <<  BLUE"       Int: Non displayable" RESET<< std::endl;
		std::cout <<  BLUE"       Float: " << toConvert << RESET << std::endl;
		std::cout <<  BLUE"       Double: Non displayable" RESET<< std::endl;
		std::cout << YELLOW "=========================================" RESET << std::endl;
	}
	else if (toConvert == "-inf" || toConvert == "+inf" || toConvert == "nan")
	{
		std::cout << YELLOW "=========================================" RESET << std::endl;
		std::cout <<  BLUE"       Char: Non displayable" RESET<< std::endl;
		std::cout <<  BLUE"       Int: Non displayable" RESET<< std::endl;
		std::cout <<  BLUE"       Float: Non displayable" RESET << std::endl;
		std::cout <<  BLUE"       Double: " << toConvert << RESET << std::endl;
		std::cout << YELLOW "=========================================" RESET << std::endl;
	}
	else
	{
		std::cout << YELLOW "=========================================" RESET << std::endl;
		std::cout <<  BLUE"       Char: Non displayable" RESET<< std::endl;
		std::cout <<  BLUE"       Int: Non displayable" RESET<< std::endl;
		std::cout <<  BLUE"       Float: Non displayable" RESET<< std::endl;
		std::cout <<  BLUE"       Double: Non displayable" RESET<< std::endl;
		std::cout << YELLOW "=========================================" RESET << std::endl;
	}
}


void printInt(std::string s1)
{
	std::cout << YELLOW "=========================================" RESET << std::endl;
	intToChar(s1);
	if (s1.length() > 10 || atoi(s1.c_str()) > INT_MAX)
		std::cout <<  BLUE"       Int: Non displayable" RESET<< std::endl;
	else
		std::cout <<  BLUE"       Int: " << atoi(s1.c_str()) << RESET<< std::endl;
	intToFloat(s1);
	intToDouble(s1);
	std::cout << YELLOW "=========================================" RESET << std::endl;
}

void	intToChar(std::string s1)
{
	long int test = atoi(s1.c_str());
	if (test < 127 && test > 0 && isprint(test))
	{
		std::cout <<  BLUE"       Char: \'" << static_cast<char>(test) <<"\'" <<RESET << std::endl;
	}
	else
	{
		std::cout <<  BLUE"       Char: Non displayable" RESET<< std::endl;
	}
}

void	intToFloat(std::string s1)
{
	long int test = atoi(s1.c_str());
	std::cout <<  BLUE"       Float: " << static_cast<float>(test) << "f" << RESET<< std::endl;
}

void	intToDouble(std::string s1)
{
	long int test = atoi(s1.c_str());
	if (test < __DBL_MAX__)
		std::cout <<  BLUE"       Double: " << static_cast<double>(test) << RESET<< std::endl;
	else
		std::cout <<  BLUE"       Double: Non displayable" RESET<< std::endl;
}

void	printChar(std::string s1)
{
	std::cout << YELLOW "=========================================" RESET << std::endl;
	std::cout <<  BLUE"       Char: \'" << s1 << "\'" << RESET << std::endl;
	charToInt(s1);
	charToFloat(s1);
	charToDouble(s1);
	std::cout << YELLOW "=========================================" RESET << std::endl;
}

void	charToFloat(std::string s1)
{
	std::cout <<  BLUE"       Float: " << static_cast<float>(s1[0]) << "f" << RESET<< std::endl;
}

void	charToDouble(std::string s1)
{
	std::cout <<  BLUE"       Double: " << static_cast<double>(s1[0]) << RESET<< std::endl;
}

void	charToInt(std::string s1)
{
	std::cout <<  BLUE"       Int: " << static_cast<int>(s1[0]) << RESET << std::endl;
}

void	printDouble(std::string s1)
{
	std::cout << YELLOW "=========================================" RESET << std::endl;
	doubleToChar(s1);
	doubleToInt(s1);
	doubleToFloat(s1);
	std::cout << BLUE "       Double: " << atof(s1.c_str()) << RESET << std::endl;
	std::cout << YELLOW "=========================================" RESET << std::endl;
}
void	doubleToChar(std::string s1)
{
	for (size_t i = 0; i < s1.length(); i++)
	{
		if (s1[i] == '.')
		{
			if (s1[i + 1])
			{
				i++;
				for (size_t a = i; a < s1.length(); a++)
				{
					if (s1[a] != '0')
					{
						std::cout <<  BLUE"       Char: Non displayable" RESET<< std::endl;
						return ;
					}
				}
				long int test = atoi(s1.c_str());
				if (test < INT_MAX && test < INT_MIN && test < 127 && isprint(test))
					std::cout <<  BLUE"       Char: \'" << static_cast<char>(test) <<"\'" <<RESET << std::endl;
				else
					std::cout <<  BLUE"       Char: Non displayable" RESET<< std::endl;
			}
			else
			{
				long int test = atoi(s1.c_str());
				if (test < INT_MAX && test < INT_MIN && test < 127 && isprint(test))
					std::cout <<  BLUE"       Char: \'" << static_cast<char>(test) <<"\'" <<RESET << std::endl;
				else
					std::cout <<  BLUE"       Char: Non displayable" RESET<< std::endl;
			}
		}
	}
}

void	doubleToFloat(std::string s1)
{
	long double test = atof(s1.c_str());
	if (test < __FLT_MAX__ && test > __FLT_MIN__)
		std::cout <<  BLUE"       Float: " << static_cast<float>(test) << "f" << RESET<< std::endl;
	else
		std::cout <<  BLUE"       Float: Non displayable" RESET<< std::endl;
}

void	doubleToInt(std::string s1)
{
	long int test = atoi(s1.c_str());
	size_t point = s1.find('.');
	if (test < __INT_MAX__ && test > INT_MIN && s1.erase(point).length() < 10)
		std::cout <<  BLUE"       Int: " << static_cast<int>(test) << RESET << std::endl;
	else
		std::cout <<  BLUE"       Int: Non displayable" RESET<< std::endl;
}

void	printFloat(std::string s1)
{
	std::cout << YELLOW "=========================================" RESET << std::endl;
	floatToChar(s1);
	floatToInt(s1);
	float test = static_cast<float>(atof(s1.c_str()));
	std::cout << BLUE "       Float: " << test << "f" << RESET << std::endl;
	floatToDouble(s1);
	std::cout << YELLOW "=========================================" RESET << std::endl;
}

void	floatToChar(std::string s1)
{
	for (size_t i = 0; i < s1.length(); i++)
	{
		if (s1[i] == '.')
		{
			if (s1[i + 1])
			{
				i++;
				for (size_t a = i; a < s1.length(); a++)
				{
					if ((s1[a] == 'f' || s1[a] == 'F') && a == i)
					{
						long int test = atoi(s1.c_str());
						if (s1.length() < 10 && test > 0 && test < 127 && isprint(test))
							std::cout <<  BLUE"       Char: \'" << static_cast<char>(test) <<"\'" <<RESET << std::endl;
						else
							std::cout <<  BLUE"       Char: Non displayable" RESET<< std::endl;
						return;
					}
					else if (isdigit(s1[a]) && s1[a] != '0')
					{
						std::cout <<  BLUE"       Char: Non displayable" RESET<< std::endl;
						return ;
					}
				}
				long int test = atoi(s1.c_str());
				if (s1.length() < 10 && test > 0 && test < 127 && isprint(test))
					std::cout <<  BLUE"       Char: \'" << static_cast<char>(test) <<"\'" <<RESET << std::endl;
				else
					std::cout <<  BLUE"       Char: Non displayable" RESET<< std::endl;
				return ;
			}
			else
			{
				long int test = atoi(s1.c_str());
				if (s1.length() < 10 && test > 0 && test < 127 && isprint(test))
					std::cout <<  BLUE"       Char: \'" << static_cast<char>(test) <<"\'" <<RESET << std::endl;
				else
					std::cout <<  BLUE"       Char: Non displayable" RESET<< std::endl;
				return ;
			}
		}
		else if ((s1[i] == 'f' || s1[i] == 'F') && s1[i + 1] == '\0')
		{
			long int test = atoi(s1.c_str());
			if (s1.length() < 10 && test > 0 && test < 127 && isprint(test))
				std::cout <<  BLUE" size_t point = s1.find('.');      Char: \'" << static_cast<char>(test) <<"\'" <<RESET << std::endl;
			else
				std::cout <<  BLUE"       Char: Non displayable" RESET<< std::endl;
			return ;
		}
	}
}

void	floatToInt(std::string s1)
{
	long int test = atoi(s1.c_str());
	size_t point = s1.find('.');
	if (test < __INT_MAX__ && test > INT_MIN && s1.erase(point).length() < 10)
		std::cout <<  BLUE"       Int: " << static_cast<int>(test) << RESET << std::endl;
	else
		std::cout <<  BLUE"       Int: Non displayable" RESET<< std::endl;
}

void	floatToDouble(std::string s1)
{
	int length = s1.length();
	s1[length - 1] = '\0';
	double tee = atof(s1.c_str());
	std::cout << BLUE "       Double: " << tee << RESET << std::endl;
}

