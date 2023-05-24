/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:51:55 by pjay              #+#    #+#             */
/*   Updated: 2023/05/19 11:00:14 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	_type = "default;"
	std::cout << CYAN "Default Constructor called" RESET << std::endl;
}

AMateria::AMateria(const AMateria& amateria)
{
	_type = amateria._type;
	std::cout << CYAN "Copy Constructor called" RESET << std::endl;
}

AMateria& AMateria::operator =(const AMateria& amateria)
{
	if (this != &amateria)
		_type = amateria._type;
	std::cout << CYAN "Copy assignement Constructor called" RESET << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << CYAN "Destructor called" RESET << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	_type = type;
	std::cout << CYAN "String Constructor called" RESET << std::endl;
}

std::string const & AMateria::getType() const //Returns the materia type
{
	return (_type);
}

// AMateria* AMateria::clone() const = 0
// {

// }

void AMateria::use(ICharacter& target)
{

}

