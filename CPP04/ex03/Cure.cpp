/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:02:10 by pjay              #+#    #+#             */
/*   Updated: 2023/05/22 11:11:13 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	_type = "cure";
	std::cout << BLUE "Constructor called" RESET << std::endl;
}

Cure::Cure(const Cure& cure)
{
	_type = cure._type;
	std::cout << BLUE "Copy Constructor called" RESET << std::endl;
}

Cure& Cure::operator =(const Cure& cure)
{
	std::cout << BLUE "Copy Assignement Constructor called" RESET << std::endl;
	if (this != &cure)
		_type = cure._type;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << BLUE "destructor called" RESET << std::endl;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
