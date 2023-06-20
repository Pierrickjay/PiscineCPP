/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:51:47 by pjay              #+#    #+#             */
/*   Updated: 2023/05/29 09:36:34 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	_brain = new Brain();
	#ifdef DEBUG
	std::cout << RED "Default constructor of Dog called" RESET<< std::endl;
	#endif
}

Dog::Dog(const Dog& dog)
{
	#ifdef DEBUG
	std::cout << RED "Copy constructor of Dog called" RESET<< std::endl;
	#endif
	_brain = new Brain(*dog._brain);
	_type = dog._type;
}

Dog& Dog::operator =(const Dog& dog)
{
	#ifdef DEBUG
	std::cout << RED "Copy Assignement of Dog constructor called" RESET<< std::endl;
	#endif
	if (this != &dog)
	{
		if (_brain)
			delete _brain;
		_brain = new Brain(*dog._brain);
		_type = dog._type;
	}
	return *this;
}

Dog::~Dog(void)
{
	delete _brain;
	#ifdef DEBUG
	std::cout << RED "Destructor of Dog called" RESET << std::endl;
	#endif
}

void Dog::makeSound(void) const
{
	std::cout << BLUE "Waouf waouf je suis un chien" RESET<< std::endl;
}

Brain* Dog::getBrain(void)
{
	return (_brain);
}
