/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:28:16 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 10:17:13 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name")
{
	std::cout << BLUE "Default constructor of Diamond Trap" RESET << std::endl;
	_name = "default";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap) : ClapTrap(diamondtrap._name + "_clap_name")
{
	std::cout << BLUE " Copie constructor called of Diamond Trap" RESET << std::endl;
	_name = diamondtrap._name;
	_hitPoints = diamondtrap.FragTrap::_hitPoints;
	_energyPoints = diamondtrap.ScavTrap::_energyPoints;
	_attackDamage = diamondtrap.FragTrap::_attackDamage;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& diamondtrap)
{
	std::cout << BLUE " copie assignement opperator called of Diamond Trap" RESET << std::endl;
	if (this != &diamondtrap)
	{
		ClapTrap::_name = diamondtrap._name + "_clap_name";
		_name = diamondtrap._name;
		_hitPoints = diamondtrap.FragTrap::_hitPoints;
		_energyPoints = diamondtrap.ScavTrap::_energyPoints;
		_attackDamage = diamondtrap.FragTrap::_attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << BLUE "Destructor called of Diamond Trap" RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << BLUE "Constructor called of Diamond Trap" RESET << std::endl;
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << _name << " my claptrap name is " << ClapTrap::_name << std::endl;
}
