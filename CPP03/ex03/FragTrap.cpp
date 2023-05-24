/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:11:36 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 11:39:46 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << RED "Default constructor of FragTrap Called" RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& fragtrap)
{
	std::cout << RED"Copie constructor of FragTrap Called" RESET<< std::endl;
	_name = fragtrap._name;
	_hitPoints = fragtrap._hitPoints;
	_energyPoints = fragtrap._energyPoints;
	_attackDamage = fragtrap._attackDamage;
}

FragTrap& FragTrap:: operator= (const FragTrap& fragtrap)
{
	std::cout << RED"Copy assignment operator of FragTrap called" RESET<< std::endl;
	if (this != &fragtrap)
	{
		_name = fragtrap._name;
		_hitPoints = fragtrap._hitPoints;
		_energyPoints = fragtrap._energyPoints;
		_attackDamage = fragtrap._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << RED"Destructor of FragTrap Called" RESET<< std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << RED"Constructor of FragTrap Called" RESET<< std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

void FragTrap::HighFivesGuys()
{
	std::ifstream file1("highfive.txt");
	std::string line;

	std::cout << "Frag Trap " << _name << " send a positive" << std::endl;
	if (!file1.is_open())
	{
		std::cout << "HIGH FIVE" << std::endl;
	}
	else
	{
		while (std::getline(file1, line))
			std::cout << line << std::endl;
	}
	file1.close();
}
