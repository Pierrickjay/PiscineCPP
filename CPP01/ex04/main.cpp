/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:21:01 by pjay              #+#    #+#             */
/*   Updated: 2023/05/15 12:40:13 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>


void	change_string(char **av, std::ifstream& file1, std::ofstream& file2)
{
	size_t	pos;
	char	c;
	std::string	fullText;
	std::string result;
	size_t	foundPos;

	pos = 0;
	foundPos = 0;
	while (!file1.eof() && file1 >> std::noskipws >> c) // noskipws : permet de garder les \n dans la copie
		fullText += c;
	while (pos < fullText.length())
	{
		if (av[2][0])
			foundPos = fullText.find(av[2], pos);
		else
		{
			result += fullText;
			break;
		}
		if (foundPos == std::string::npos)
		{
			result += fullText.substr(pos);
			break ;
		}
		result += fullText.substr(pos, foundPos - pos);
		if (av[3][0])
			result += av[3];
		pos = foundPos + std::string(av[2]).size();
	}
	result += '\n';
	file2 << result;
}

int main(int ac, char **av)
{
	std::string test;
	if (ac != 4)
	{
		std::cout << "Please enter 3 parametters" << std::endl;
		std::cout << "a filename and two strings, s1 and s2." << std::endl;
		return (0);
	}
	std::ifstream file1(av[1]);
	if (!file1.is_open())
	{
		std::cout << "Unable to open file" << std::endl;
		return (0);
	}
	test = av[1];
	std::ofstream file2(test.append(".replace").c_str());
	if (!file2.is_open())
	{
		std::cout << "Unable to open file" << std::endl;
		return (0);
	}
	change_string(av, file1, file2);
	file1.close();
	file2.close();
}
