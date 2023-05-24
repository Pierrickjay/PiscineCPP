/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:04:34 by pjay              #+#    #+#             */
/*   Updated: 2023/05/19 11:55:02 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal* test[100];
	Dog Basic;
	{
		Dog Tmp = Basic;
	}
	for (int a = 0; a < 50; a++)
	{
		test[a] = new Dog();
	}
	for (int a = 50; a < 100; a++)
	{
		test[a] = new Cat();
	}
	// pour ce qui est de en dessous il est probable que mettre en virtual permet d'eviterle cast
	std::cout << "A l'index 32 du chien numero 32 il y a " << static_cast<Dog*>(test[32])->getBrain()->getArrayNumber(32) << std::endl;
	static_cast<Dog*>(test[32])->getBrain()->setArrayNumber("Un numero au hasard", 32);
	std::cout << "A l'index 32  du chien numero 32 apres modifiction il y a " << static_cast<Dog*>(test[32])->getBrain()->getArrayNumber(32) << std::endl;
	for (int a = 0; a < 100; a++)
	{
		delete test[a];
	}
	delete j;//should not create a leak
	delete i;
	return 0;
}
