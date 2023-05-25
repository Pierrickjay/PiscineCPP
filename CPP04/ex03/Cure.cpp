/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:02:10 by pjay              #+#    #+#             */
/*   Updated: 2023/05/24 14:35:56 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	_type = "cure";
	#ifdef DEBUG
	std::cout << BLUE "Constructor of Ice called" RESET << std::endl;
	#endif
}

Cure::Cure(const Cure& cure)
{
	_type = cure._type;
	#ifdef DEBUG
	std::cout << BLUE "Copy Constructor of Ice called" RESET << std::endl;
	#endif
}

Cure& Cure::operator =(const Cure& cure)
{
	#ifdef DEBUG
	std::cout << BLUE "Copy Assignement Constructor of Ice called" RESET << std::endl;
	#endif
	if (this != &cure)
		_type = cure._type;
	return (*this);
}

Cure::~Cure(void)
{
	#ifdef DEBUG
	std::cout << BLUE "destructor of Ice called" RESET << std::endl;
	#endif
}

AMateria* Cure::clone() const
{
	Cure *loowe = new Cure();
	return (loowe);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
