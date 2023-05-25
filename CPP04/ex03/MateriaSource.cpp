/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:38:21 by pjay              #+#    #+#             */
/*   Updated: 2023/05/24 15:46:51 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
	#ifdef DEBUG
		std::cout << CYAN "Constructor of Materia Source called" RESET << std::endl;
	#endif
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
	for (int i = 0; i < 4; i++)
		{
			if (materiaSource._inventory[i] != NULL)
				_inventory[i] = materiaSource._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	#ifdef DEBUG
		std::cout << CYAN "Constructor of Materia Source called" RESET << std::endl;
	#endif
}

MateriaSource& MateriaSource::operator =(const MateriaSource& materiaSource)
{
	if (this != &materiaSource)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materiaSource._inventory[i] != NULL)
				_inventory[i] = materiaSource._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	#ifdef DEBUG
		std::cout << CYAN "Constructor of Materia Source called" RESET << std::endl;
	#endif
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	#ifdef DEBUG
		std::cout << CYAN "Constructor of Materia Source called" RESET << std::endl;
	#endif
}

void MateriaSource::learnMateria(AMateria *mat)
{
	if (mat)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!_inventory[i])
			{
				_inventory[i] = mat->clone();
				delete mat;
				return ;
			}
		}
	}
	else
	{
		std::cout << "Unable to learn a NULL Materia" << std::endl;
	}

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i]->getType() == type)
		{
			return (_inventory[i]->clone());
		}
	}
	return (NULL);
}
