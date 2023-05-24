/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:47:54 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 17:44:45 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << "Default constructor of Wrong Cat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat)
{
	std::cout << "Copy constructor of Wrong Cat called" << std::endl;
	_type = wrongcat._type;
}

WrongCat& WrongCat::operator =(const WrongCat& wrongcat)
{
	std::cout << "Copy Assignement constructor of Wrong Cat called" << std::endl;
	if (this != &wrongcat)
		_type = wrongcat._type;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor of Wrong Cat called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "miaou miaou je suis UN CHATTT" << std::endl;
}
