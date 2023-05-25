/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:51:55 by pjay              #+#    #+#             */
/*   Updated: 2023/05/25 10:43:10 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	_type = "default";
	#ifdef DEBUG
	std::cout << CYAN "Default Constructor of AMateria called" RESET << std::endl;
	#endif
}

AMateria::AMateria(const AMateria& amateria)
{
	_type = amateria._type;
	#ifdef DEBUG
		std::cout << CYAN "Copy Constructor of AMateria called" RESET << std::endl;
	#endif
}

AMateria& AMateria::operator =(const AMateria& amateria)
{
	if (this != &amateria)
		_type = amateria._type;
	#ifdef DEBUG
		std::cout << CYAN "Copy assignement Constructor of AMateria called" RESET << std::endl;
	#endif
	return *this;
}

AMateria::~AMateria(void)
{
	#ifdef DEBUG
	std::cout << CYAN "Destructor of AMateria called" RESET << std::endl;
	#endif
}

AMateria::AMateria(std::string const & type)
{
	_type = type;
	#ifdef DEBUG
	std::cout << CYAN "String Constructor of AMateria called" RESET << std::endl;
	#endif
}

std::string const & AMateria::getType() const //Returns the materia type
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "use of AMateria func on " << target.getName() << std::endl;
}
