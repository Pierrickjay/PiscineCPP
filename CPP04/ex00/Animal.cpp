/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:37:35 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 17:45:08 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Empty")
{
	std::cout << CYAN "Default constructor of Animal called" RESET<< std::endl;
}

Animal::Animal(const Animal& animal)
{
	std::cout << CYAN "Copy constructor of Animal called" RESET<< std::endl;
	_type = animal._type;
}

Animal& Animal::operator =(const Animal& animal)
{
	std::cout << CYAN "Copy Assignement of Animal constructor called" RESET<< std::endl;
	if (this != &animal)
	{
		_type = animal._type;
	}
	return *this;
}

Animal::~Animal(void)
{
	std::cout << CYAN "Destructor of Animal called" RESET<< std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << BLUE "je suis un animal sans trop d'interet" RESET<< std::endl;
}

std::string Animal::getType(void) const
{
	return (_type);
}
