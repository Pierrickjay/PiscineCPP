/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:04:34 by pjay              #+#    #+#             */
/*   Updated: 2023/05/29 13:16:26 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	i->makeSound();
	j->makeSound();
	//Animal test;
	delete j;
	delete i;
	Cat *aristochat = new Cat();
	Cat *test_1 = new Cat();
	//Cat *test_3 = test_1;

	std::cout << "aristocha is a " << aristochat->getType() << std::endl;
	std::cout << "This is his brain -> " << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << " " << aristochat->getBrain()->getArrayNumber(i);
			if (i == 10 - 1 ||i == 20 - 1||i == 30 - 1|| i == 40 - 1|| i == 50- 1|| i == 60- 1|| i == 70- 1|| i == 80 - 1|| i == 90- 1)
			std::cout << std::endl;
	}
	std::cout << std::endl << "Ok now we can change the number 50(picked randomly) with whatever you want " << std::endl;
	std::string toReplace;
	std::cout << "Write something to replace" << std::endl;
	std::cin >> toReplace;
	aristochat->getBrain()->setArrayNumber(toReplace, 49);
	std::cout << "new brain ->>>>>>>>" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << " " << aristochat->getBrain()->getArrayNumber(i);
		if (i == 10 - 1 ||i == 20 - 1||i == 30 - 1|| i == 40 - 1|| i == 50- 1|| i == 60- 1|| i == 70- 1|| i == 80 - 1|| i == 90- 1)
			std::cout << std::endl;
	}
	std::cout << std::endl << "Brain of an other cat->>>>>>>>" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << " " << test_1->getBrain()->getArrayNumber(i);
		if (i == 10 - 1 ||i == 20 - 1||i == 30 - 1|| i == 40 - 1|| i == 50- 1|| i == 60- 1|| i == 70- 1|| i == 80 - 1|| i == 90- 1)
			std::cout << std::endl;
	}
	std::cout << std::endl;
	Cat test_2(*test_1);
	test_2 = *aristochat;
	delete test_1;
	delete aristochat;

}
