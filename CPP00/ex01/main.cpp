/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:42:00 by pjay              #+#    #+#             */
/*   Updated: 2023/04/03 14:09:43 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

bool solve(string s)
{
	if (s.length() > 1)
		return false;
	for( int i = 0; i < (int)s.length(); i++ ) {
		if(!isdigit(s[i]) || s[i] == '8' || s[i] == '9') {
			return false;
		}
	}
	return true;
}

void	dealWithSearch(Contact *contact)
{
	int		i;
	string	str;

	i = 0;
	while (i < 8)
	{
		std::cout << "         " << i << "|";
		contact[i].printContact();
		std::cout << std::endl;
		i++;
	}
	std::cout << "Choose the index you want to see information between 0 and 7 : " << std::endl;
	while (std::getline(std::cin, str))
	{
		if (solve(str) == false)
			std::cout << "Please respect what's below" << std::endl;
		else
		{
 			contact[(int)str[0] - '0'].printAllContact();
			break ;
		}
		std::cout << "Choose the index you want to see information between 0 and 7 : ";
	}
}
void	dealWithAdd(Contact *contact)
{
	contact->setFirstName();
	contact->setLastName();
	contact->setNickname();
	contact->setPhoneNumber();
	contact->setDarkestSecret();
	std::cout << "Contact Added to the Phone Book" << std::endl;
}

int main()
{
	PhoneBook book;
	string	str;
	int		i;

	i = 0;
	std::cout << "Phone Book is empty\n";
	std::cout << "You can ADD a contact, SEARCH a contact and EXIT to quit programme" << std::endl;
	while (std::getline(std::cin, str))
	{
		if (!str.compare("ADD"))
		{
			dealWithAdd(&book.contact[i]);
			i++;
		}
		else if (!str.compare("SEARCH"))
			dealWithSearch(book.contact);
		else if (!str.compare("EXIT"))
			break ;
		else
			std::cout << "Please enter something that exist" << std::endl;
		if (i == 8)
			i = 0;
		std::cout << "You can ADD a contact, SEARCH a contact and EXIT to quit programme" << std::endl;
	}
	std::cout << "Exit" << std::endl;
}
