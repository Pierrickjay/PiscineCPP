/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:51:47 by pjay              #+#    #+#             */
/*   Updated: 2023/05/25 10:49:29 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << RED "Default constructor of Dog called" RESET<< std::endl;
}

Dog::Dog(const Dog& dog)
{
	std::cout << RED "Copy constructor of Dog called" RESET<< std::endl;
	_brain = new Brain(*dog._brain);
	_type = dog._type;
}

Dog& Dog::operator =(const Dog& dog)
{
	std::cout << RED "Copy Assignement of Dog constructor called" RESET<< std::endl;
	if (this != &dog)
	{
		_brain = new Brain(*dog._brain);
		_type = dog._type;
	}
	return *this;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << RED "Destructor of Dog called" RESET << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Waouf waouf je suis un chien" << std::endl;
}

Brain* Dog::getBrain(void)
{
	return (_brain);
}
