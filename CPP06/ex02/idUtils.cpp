/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idUtils.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:33:05 by pjay              #+#    #+#             */
/*   Updated: 2023/06/15 16:53:22 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "idUtils.hpp"

Base * generate(void)
{
	Base *ptr = NULL;
	srand(time(NULL));
	int randtime = rand() % 3;
	switch (randtime)
	{
	case 0 :
		ptr = new A;
		break;
	case 1 :
		ptr = new B;
		break;
	default:
		ptr = new C;
		break;
	}
	return ptr;
}

// void identify(Base* p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C".


void identify(Base* p)
{
	if (A* ptr = dynamic_cast<A *>(p))
	{
		std::cout << "La base est de type A" << std::endl;
	}
	else if (B* ptr = dynamic_cast<B *> (p))
	{
		std::cout << "La base est de type B" << std::endl;
	}
	else
	{
		std::cout << "La base est de type C" << std::endl;
	}
}

// void identify(Base& p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
// inside this function is forbidden.

void identify(Base& p)
{
	try
	{
		A &refA = dynamic_cast<A&>(p);
		std::cout << "La base est de type A" << std::endl;
		(void)refA;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &refB = dynamic_cast<B&>(p);
			(void)refB;
			std::cout << "La base est de type B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &refC = dynamic_cast<C&>(p);
				(void)refC;
				std::cout << "La base est de type C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "this reference doesn't match any object" << std::endl;
			}
		}
	}
}

