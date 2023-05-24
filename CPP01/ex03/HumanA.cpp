/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:37:39 by pjay              #+#    #+#             */
/*   Updated: 2023/04/21 10:14:34 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _gun.getType() << std::endl;
}

HumanA::HumanA(string name, Weapon& gun) : _gun(gun), _name(name)
{
	std::cout << "HumanA created his name is " << name << " his weapon is " << gun.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "Destroyer called" << std::endl;
}
