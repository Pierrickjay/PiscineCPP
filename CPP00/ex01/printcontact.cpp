/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcontact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:49:33 by pjay              #+#    #+#             */
/*   Updated: 2023/03/28 15:48:32 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::printTest(void)
{
	std::cout << _first_name << std::endl;
}


void Contact::printLastName(void)
{
	int size;

	size = _last_name.length();
	if (!_last_name.empty())
	{
		if (_last_name.length() < 10)
		{
			while (10 - size != 0)
			{
				std::cout << " ";
				size++;
			}
			std::cout << _last_name;
		}
		else if (_last_name.length() > 10)
			std::cout << _last_name.substr(0, 9) << ".";
		else
			std::cout << _last_name.substr(0, 10);
	}
	else
		std::cout << "          ";
}

void Contact::printFirstName(void)
{
	int size;

	size = _first_name.length();
	if (!(_first_name.empty()))
	{
		if (_first_name.length() < 10)
		{
			while (10 - size != 0)
			{
				std::cout << " ";
				size++;
			}
			std::cout << _first_name;
		}
		else if (_first_name.length() > 10)
			std::cout << _first_name.substr(0, 9) << ".";
		else
			std::cout << _first_name.substr(0, 10);
	}
	else
		std::cout << "          ";
}

void Contact::printNickname(void)
{
	int size;

	size = _nickname.length();
	if (!(_nickname.empty()))
	{
		if (_nickname.length() < 10)
		{
			while (10 - size != 0)
			{
				std::cout << " ";
				size++;
			}
			std::cout << _nickname;
		}
		else if (_nickname.length() > 10)
			std::cout << _nickname.substr(0, 9) << ".";
		else
			std::cout << _nickname.substr(0, 10);
	}
	else
		std::cout << "          ";
}

void Contact::printContact(void)
{
	this->printFirstName();
	std::cout << "| ";
	this->printLastName();
	std::cout << "| ";
	this->printNickname();
}

void Contact::printAllContact(void)
{
	if (_first_name.empty())
	{
		std::cout << "Ce contact est vide" << std::endl;
		return ;
	}
	std::cout << "First name :" << _first_name << std::endl;;
	std::cout << "Last name :" << _last_name << std::endl;;
	std::cout << "Nickname :" << _nickname << std::endl;;
	std::cout << "Phone number :" << _phone_number << std::endl;;
	std::cout << "Darkest secret :" << _darkest_secret << std::endl;;
}
