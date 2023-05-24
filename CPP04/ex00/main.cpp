/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:04:34 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 17:05:36 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	/************************Main Perso********************/
	const WrongAnimal* Alan = new WrongAnimal();
	const WrongAnimal* Axel = new WrongCat();
	const WrongCat* Julien = new WrongCat();
	std::cout << Axel->getType() << " " << std::endl;
	std::cout << Axel->getType() << " " << std::endl;
	std::cout << Alan->getType() << " " << std::endl;
	Axel->makeSound();
	Alan->makeSound();
	Julien->makeSound();
	delete Alan;
	delete Axel;
	delete Julien;
	return 0;
}
