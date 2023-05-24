/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:50:59 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 17:43:22 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	std::cout << MAGENTA "Default constructor of Cat called" RESET<< std::endl;
}

Cat::Cat(const Cat& cat)
{
	std::cout << MAGENTA "Copy constructor of Cat called" RESET<< std::endl;
	_type = cat._type;
}

Cat& Cat::operator =(const Cat& cat)
{
	std::cout << MAGENTA "Copy Assignement of Cat constructor called" RESET<< std::endl;
	if (this != &cat)
		_type = cat._type;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << MAGENTA "Destructor of Cat called" RESET<< std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << BLUE "miaou miaou je suis UN CHAT" RESET<< std::endl;
}
