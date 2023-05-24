/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:51:47 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 17:43:39 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	std::cout << RED "Default constructor of Dog called" RESET<< std::endl;
}

Dog::Dog(const Dog& dog)
{
	std::cout << RED "Copy constructor of Dog called" RESET<< std::endl;
	_type = dog._type;
}

Dog& Dog::operator =(const Dog& dog)
{
	std::cout << RED "Copy Assignement of Dog constructor called" RESET<< std::endl;
	if (this != &dog)
		_type = dog._type;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << RED "Destructor of Dog called" RESET << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << BLUE "Waouf waouf je suis un chien" RESET<< std::endl;
}
