/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:50:59 by pjay              #+#    #+#             */
/*   Updated: 2023/05/25 11:04:48 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	_brain = new Brain();
	_type = "Cat";
	#ifdef DEBUG
	std::cout << MAGENTA "Default constructor of Cat called" RESET<< std::endl;
	#endif
}

Cat::Cat(const Cat& cat)
{
	#ifdef DEBUG
	std::cout << MAGENTA "Copy constructor of Cat called" RESET<< std::endl;
	#endif
	_type = cat._type;
	_brain = new Brain(*cat._brain);
}

Cat& Cat::operator =(const Cat& cat)
{
	#ifdef DEBUG
	std::cout << MAGENTA "Copy Assignement of Cat constructor called" RESET<< std::endl;
	#endif
	if (this != &cat)
	{
		_type = cat._type;
		 _brain = new Brain(*cat._brain);
	}
	return *this;
}

Cat::~Cat(void)
{
	delete _brain;
	#ifdef DEBUG
	std::cout << MAGENTA "Destructor of Cat called" RESET<< std::endl;
	#endif
}

void Cat::makeSound(void) const
{
	std::cout << BLUE "miaou miaou je suis UN CHAT" RESET<< std::endl;
}

Brain* Cat::getBrain(void)
{
	return (_brain);
}
