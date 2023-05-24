/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:18:58 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 09:10:16 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << RED "Default constructor of ScavTrap Called" RESET << std::endl;
	_name = "default";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap)
{
	std::cout << RED"Copie constructor of ScavTrap Called" RESET<< std::endl;
	_name = scavtrap._name;
	_hitPoints = scavtrap._hitPoints;
	_energyPoints = scavtrap._energyPoints;
	_attackDamage = scavtrap._attackDamage;
}

ScavTrap& ScavTrap:: operator= (const ScavTrap& scavtrap)
{
	std::cout << RED"Copy assignment operator of ScavTrap called" RESET<< std::endl;
	if (this != &scavtrap)
	{
		_name = scavtrap._name;
		_hitPoints = scavtrap._hitPoints;
		_energyPoints = scavtrap._energyPoints;
		_attackDamage = scavtrap._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << RED"Destructor of ScavTrap Called" RESET<< std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << RED"Constructor of ScavTrap Called" RESET<< std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now  in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints >= 1 && _hitPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target;
		std::cout << " , causing " << _attackDamage << " points of damage" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " can't attacks because have no enerygy left or hit point left" << std::endl;
	}
}
