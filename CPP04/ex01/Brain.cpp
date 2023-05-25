/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:46:31 by pjay              #+#    #+#             */
/*   Updated: 2023/05/25 10:58:45 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain(void)
{
	#ifdef DEBUG
	std::cout << MAGENTA "Default constructor of Brain called" RESET<< std::endl;
	#endif
}

Brain::Brain(const Brain& cerveau)
{
	for (int i = 0 ; i < 100; i++)
			_ideas[i] = cerveau._ideas[i];
	#ifdef DEBUG
	std::cout << MAGENTA "Copy constructor of Brain called" RESET<< std::endl;
	#endif
}

Brain& Brain::operator =(const Brain& cerveau)
{
	#ifdef DEBUG
	std::cout << MAGENTA "Copy Assignement of Brain constructor called" RESET<< std::endl;
	#endif
	if (this != &cerveau)
	{
		for (int i = 0 ; i < 100; i++)
			_ideas[i] = cerveau._ideas[i];
	}
	return *this;
}

Brain::~Brain(void)
{
	#ifdef DEBUG
	std::cout << MAGENTA "Destructor of Brain called" RESET<< std::endl;
	#endif
}

std::string Brain::_ideas[100] = {
	"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25",\
	"26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50",\
	"51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", \
	"75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99"
};

void Brain::setArrayNumber(std::string ideas, int N)
{
	if (N < 100)
		_ideas[N] = ideas;
	else
		std::cout << "Number higher that 100" << std::endl;
}

std::string Brain::getArrayNumber(int N)
{
	if (N < 100)
		return (_ideas[N]);
	else
		return ("NULL");
}

