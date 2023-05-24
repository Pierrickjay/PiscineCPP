/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:00:54 by pjay              #+#    #+#             */
/*   Updated: 2023/05/22 11:11:35 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	_type = "ice";
	std::cout << BLUE "Constructor called" RESET << std::endl;
}

Ice::Ice(const Ice& ice)
{
	_type = ice._type;
	std::cout << BLUE "Copy Constructor called" RESET << std::endl;
}

Ice& Ice::operator =(const Ice& ice)
{
	std::cout << BLUE "Copy Assignement Constructor called" RESET << std::endl;
	if (this != &ice)
		_type = ice._type;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << BLUE "destructor called" RESET << std::endl;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
