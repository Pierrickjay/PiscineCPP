/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:44:23 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 17:44:12 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongAnimal::WrongAnimal(void) : _type("Empty")
{
	std::cout << "Default constructor of Wrong Animal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal)
{
	std::cout << "Copy constructor of Wrong Animalcalled" << std::endl;
	_type = wronganimal._type;
}

WrongAnimal& WrongAnimal::operator =(const WrongAnimal& wronganimal)
{
	std::cout << "Copy Assignement constructor of Wrong Animal called" << std::endl;
	if (this != &wronganimal)
	{
		_type = wronganimal._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor of Wrong Animal called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "je suis un WrongAnimal sans trop d'interet" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (_type);
}
