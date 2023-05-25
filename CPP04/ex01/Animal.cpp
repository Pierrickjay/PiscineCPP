/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:37:35 by pjay              #+#    #+#             */
/*   Updated: 2023/05/25 11:31:53 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Empty")
{
	#ifdef DEBUG
	std::cout << CYAN "Default constructor of Animal called" RESET<< std::endl;
	#endif
}

Animal::Animal(const Animal& animal)
{
	#ifdef DEBUG
	std::cout << CYAN "Copy constructor of Animal called" RESET<< std::endl;
	#endif
	_type = animal._type;
}

Animal& Animal::operator =(const Animal& animal)
{
	#ifdef DEBUG
	std::cout << CYAN "Copy Assignement of Animal constructor called" RESET<< std::endl;
	#endif
	if (this != &animal)
	{
		_type = animal._type;
	}
	return *this;
}

Animal::~Animal(void)
{
	#ifdef DEBUG
	std::cout << CYAN "Destructor of Animal called" RESET<< std::endl;
	#endif
}

void Animal::makeSound(void) const
{
	#ifdef DEBUG
	std::cout << BLUE "je suis un animal sans trop d'interet" RESET<< std::endl;
	#endif
}

std::string Animal::getType(void) const
{
	return (_type);
}
