/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:00:54 by pjay              #+#    #+#             */
/*   Updated: 2023/05/24 15:39:35 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	_type = "ice";

	#ifdef DEBUG
		std::cout << BLUE "Constructor of Cure called" RESET << std::endl;
	#endif
}

Ice::Ice(const Ice& ice)
{
	_type = ice._type;
	#ifdef DEBUG
	std::cout << BLUE "Copy Constructor of Cure called" RESET << std::endl;
	#endif
}



Ice& Ice::operator =(const Ice& ice)
{
	#ifdef DEBUG
		std::cout << BLUE "Copy Assignement Constructor of Cure called" RESET << std::endl;
	#endif
	if (this != &ice)
		_type = ice._type;
	return (*this);
}

Ice::~Ice(void)
{
	#ifdef DEBUG
		std::cout << BLUE "destructor of Cure called" RESET << std::endl;
	#endif
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
