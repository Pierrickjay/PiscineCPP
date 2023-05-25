/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:41:48 by pjay              #+#    #+#             */
/*   Updated: 2023/05/25 10:46:28 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	_name = "default";
	_materiaCount = 0;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	#ifdef DEBUG
		std::cout << CYAN"Constructor of Character Called" RESET << std::endl;
	#endif
}

Character::Character(const Character& character)
{
	_name = character._name;
	_materiaCount = character._materiaCount;
	for (int i = 0; i < 4; i++)
	{
		if (!character._inventory[i])
			_inventory[i] = character._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	#ifdef DEBUG
		std::cout << CYAN"Constructor copy of Character Called" RESET << std::endl;
	#endif
}
Character& Character::operator =(const Character& character)
{
	#ifdef DEBUG
		std::cout << CYAN"Constructor copy assignement of Character Called" RESET << std::endl;
	#endif
	if (this != &character)
	{
		_name = character._name;
		for (int i = 0; i < 4; i++)
		{
			if (!character._inventory[i])
				_inventory[i] = character._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		_materiaCount = character._materiaCount;
	}
	return *this;
}
Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	#ifdef DEBUG
		std::cout << CYAN"destructor of Character Called" RESET << std::endl;
	#endif
}
Character::Character(std::string name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	#ifdef DEBUG
		std::cout << CYAN"Constructor with string Called" RESET << std::endl;
	#endif
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i] && m)
		{
			_inventory[i] = m;
			_materiaCount++;
			#ifdef DEBUG
				std::cout << BLUE"Materia Equiped"RESET << std::endl;
			#endif
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (_inventory[idx])
	{
		_inventory[idx] = NULL;
		_materiaCount--;
		#ifdef DEBUG
			std::cout << "Materia Equiped" << std::endl;
		#endif
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4)
		_inventory[idx]->use(target);
	else
		std::cout << "cannot use with this idx" << std::endl;
}

