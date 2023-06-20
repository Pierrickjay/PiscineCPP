/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:46:31 by pjay              #+#    #+#             */
/*   Updated: 2023/05/29 09:29:51 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>


Brain::Brain(void)
{
	#ifdef DEBUG
	std::cout << MAGENTA "Default constructor of Brain called" RESET<< std::endl;
	#endif
	for (int i = 0; i < 100 ; i++)
		_ideas[i] ="Neurone";
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

