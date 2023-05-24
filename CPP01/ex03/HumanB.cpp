/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:27:15 by pjay              #+#    #+#             */
/*   Updated: 2023/05/06 15:11:38 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack(void)
{
	if (!_gun)
		std::cout << "No Gun" << std::endl;
	else
		std::cout << _name << " attacks with their " << _gun->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &gun)
{
	if (_name.empty())
		std::cout << "no name"<< std::endl;
	else
		std::cout << "name of humanB is " << _name << std::endl;
	if (_gun == NULL)
		_gun = &gun;
}

HumanB::HumanB(string name)
{
	if (name.empty())
	{
		std::cout << "the name is NULL so i assigned the name NULL to humanB";
		_name = "NULL";
	}
	else
		_name = name;
	_gun = NULL;
	std::cout << "Humanb was created" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "Destroyer called on HumanB" << std::endl;
}
