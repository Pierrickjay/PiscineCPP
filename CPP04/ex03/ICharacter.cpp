/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:47:27 by pjay              #+#    #+#             */
/*   Updated: 2023/05/22 11:41:15 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{
	std::cout << CYAN "Constructor of ICharacter called" RESET << std::endl;
}

ICharacter::ICharacter(const ICharacter& icharacter)
{
	std::cout << CYAN "Copy Constructor of ICharacter called" RESET << std::endl;
}

ICharacter& ICharacter::operator =(const ICharacter& icharacter)
{
	std::cout << CYAN "Copy assignement Constructor of ICharacter called" RESET << std::endl;
}

ICharacter::~ICharacter(void)
{
	std::cout << CYAN "Destructor of ICharacter called" RESET << std::endl;
}


ICharacter::ICharacter(std::string name)
{

}

std::string const & ICharacter::getName() const
{

}

void ICharacter::equip(AMateria* m)
{
	
}

void ICharacter::unequip(int idx)
{

}

void ICharacter::use(int idx, ICharacter& target)
{

}


