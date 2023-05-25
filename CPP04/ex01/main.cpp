/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:04:34 by pjay              #+#    #+#             */
/*   Updated: 2023/05/25 11:48:40 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	/*********************************MAIN OF SUBJECT**********************************/
	Animal* test[100];
	// Dog Basic;
	// {
	// 	Dog Tmp = Basic;
	// }
	for (int a = 0; a < 50; a++)
	{
		test[a] = new Dog();
	}
	for (int a = 50; a < 100; a++)
	{
		test[a] = new Cat();
	}
	for (int a = 0; a < 100; a++)
	{
		delete test[a];
	}
	/****************************MAIN PERSO**************************/
	Cat *aristochat = new Cat();

	std::cout << "aristocha is a " << aristochat->getType() << std::endl;
	std::cout << "he loves math and there is only number in his brain -> " << std::endl;
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
	std::cout << std::endl;
	delete aristochat;
}
