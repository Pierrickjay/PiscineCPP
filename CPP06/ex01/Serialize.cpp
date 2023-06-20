/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:13:57 by pjay              #+#    #+#             */
/*   Updated: 2023/06/15 14:56:31 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::Serialize()
{
	std::cout << YELLOW"Constructor of Serialize called "RESET << std::endl;
}

Serialize::Serialize(const Serialize& rhs)
{
	(void)rhs;
	std::cout << YELLOW"Constructor by assignement of Serialize called"RESET << std::endl;
}

Serialize& Serialize::operator= (const Serialize& rhs)
{
	(void)rhs;
	return *this;
	std::cout << YELLOW"Constructor by operator of Serialize called"RESET << std::endl;
}

Serialize::~Serialize()
{
	std::cout << YELLOW"Destructor of Serialize called"RESET << std::endl;
}

uintptr_t Serialize::serialize(Data* ptr)
{
	uintptr_t Rawptr = reinterpret_cast<uintptr_t>(ptr);
	return (Rawptr);
}

Data* Serialize::deserialize(uintptr_t raw)
{
	std::cout << "Trying to cast from a Raw uintptr to a Data* object" << std::endl;
	Data *ptr = reinterpret_cast<Data *>(raw); // reinterpret_cast bc entier non signer
	if (ptr == NULL)
		throw ConversionImpossible();
	else
	{
		std::cout << "Conversion Succeed" << std::endl;
		return (ptr);
	}
	return (ptr);
}

const char* Serialize::ConversionImpossible::what() const throw()
{
	return ("Conversion failed");
}
