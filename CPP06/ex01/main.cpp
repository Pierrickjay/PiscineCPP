/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:56:17 by pjay              #+#    #+#             */
/*   Updated: 2023/06/15 14:52:25 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serialize.hpp"

int main()
{
	Data *ptr = new Data("Old One");
	Serialize info;
	Data *ptrNull = NULL;
	uintptr_t ptrInt;
	Data *ptrData;

	try
	{
		std::cout << "Adress of the class before using the function : "<< &ptr << std::endl;
		ptrInt = info.serialize(ptr);
		std::cout << "Adress after the serialize = " << &ptrInt << std::endl;
		ptrData = info.deserialize(ptrInt);
		std::cout << "_name after the deserialize = " << ptrData->getName() << std::endl;
		ptrInt = info.serialize(ptrNull);
		std::cout << "Adress after the serialize = " << &ptrInt << std::endl;
		ptrData = info.deserialize(ptrInt);
		std::cout << "_name after the deserialize = " << ptrData->getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "problem : " << e.what() << '\n';
	}
	delete ptr;
}
