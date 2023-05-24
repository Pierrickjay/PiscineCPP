/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:57:46 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 10:19:39 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "Name: " << name << std::endl;
	std::cout <<CYAN "constructor called" RESET<< std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(void) : _name("Default")
{
	std::cout << CYAN "constructor called" RESET<< std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints >= 1 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target;
		this->_energyPoints--;
		std::cout << " , causing " << _attackDamage << " points of damage" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " can't attacks because have no enerygy left or hit point left" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0 && amount < UINT_MAX && this->_hitPoints - (int)amount > INT_MIN)
	{
		std::cout << "ClapTrap " << _name << " took damage and loose " << amount << " of hit point" << std::endl;
		std::cout << "ClapTrap " << _name << " had " << this->_hitPoints << " hit points before that" << std::endl;
		this->_hitPoints = this->_hitPoints - amount;
		std::cout << "ClapTrap " << _name << " has now " << this->_hitPoints << " hit points" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << "have already no point left " << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints >= 1 && _hitPoints > 0 && this->_hitPoints + amount < INT_MAX)
	{
		std::cout << "ClapTrap " << _name << " repaired hit self and gain " << amount << " of hit point " << std::endl;
		this->_hitPoints = this->_hitPoints + amount;
		this->_energyPoints--;
		std::cout << "ClapTrap " << _name << " has now " << this->_hitPoints << " of energy" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " can't repaire hiself because have no enerygy left or hit point left" << std::endl;
	}
}

ClapTrap::~ClapTrap(void)
{
	std::cout << CYAN "Destructor called" RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	std::cout << CYAN "Copy constructor called" RESET<< std::endl;
	*this = claptrap;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& claptrap)
{
	std::cout << CYAN "Copy assignment operator called" RESET << std::endl;
	if (this != &claptrap)
	{
		this->_hitPoints = claptrap._hitPoints;
		this->_energyPoints = claptrap._energyPoints;
		this->_attackDamage = claptrap._attackDamage;
	}
	return *this;
}
