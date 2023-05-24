/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:30:38 by pjay              #+#    #+#             */
/*   Updated: 2023/04/03 15:28:30 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

/*The contact fields are: first name, last name, nickname, phone number, and
darkest secret.*/

bool	check_if_one(string str)
{
	int a;

	a = 0;
	for (int i = 0; i < (int)str.length() ; i++)
	{
		if (isalpha(str[i]))
			return true;
	}
	return (false);
}


bool	check_if_num(string str)
{
	int a;

	a = 0;
	for (int i = 0; i < (int)str.length() ; i++)
	{
		if(!isdigit(str[i]))
		{
			if (str[i] != ' ')
				return (false);
		}
	}
	return (true);
}

void Contact::setFirstName(void)
{
	string str;

	std::cout << "First_name  ";
	while (std::getline(std::cin, str))
	{
		if (str.empty() == true || check_if_one(str) == false)
			std::cout << "please enter something with at least one alphacaractere" << std::endl;
		else
			break;
		std::cout << "First_name  ";
	}
	_first_name = str;
}

void Contact::setLastName(void)
{
	string str;

	std::cout << "Last_name  ";
	while (std::getline(std::cin, str))
	{
		if (str.empty() == true || check_if_one(str) == false)
			std::cout << "please enter something with at least one alphacaractere" << std::endl;
		else
			break;
		std::cout << "Last_name  ";
	}
	_last_name = str;
}
void Contact::setNickname(void)
{
	string str;
	std::cout << "Nickname  ";
	while (std::getline(std::cin, str))
	{
		if (str.empty() == true || check_if_one(str) == false)
			std::cout << "please enter something with at least one alphacaractere" << std::endl;
		else
			break;
		std::cout << "Nickname  ";
	}
	_nickname = str;
}
void Contact::setPhoneNumber(void)
{
	string str;
	std::cout << "Phone Number  ";
	while (std::getline(std::cin, str))
	{

		if (str.empty() == true || check_if_num(str) == false)
			std::cout << "please enter something with only number and space" << std::endl;
		else
			break;
		std::cout << "Phone Number  ";
	}
	_phone_number = str;
}
void Contact::setDarkestSecret(void)
{
	string str;

	std::cout << "Darkest Secret  ";
	while (std::getline(std::cin, str))
	{
		if (str.empty() == true || check_if_one(str) == false)
			std::cout << "please enter something with at least one alphacaractere" << std::endl;
		else
			break;
		std::cout << "Darkest Secret  ";
	}
	_darkest_secret = str;
}
