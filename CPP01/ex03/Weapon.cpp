/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:20:29 by pjay              #+#    #+#             */
/*   Updated: 2023/03/31 16:09:34 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const string &Weapon::getType(void)
{
	return (_type);
}

void Weapon::setType(string toChange)
{
	_type = toChange;
}

Weapon::Weapon(string gun) : _type(gun)
{
	std::cout << "Weapon created" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon destroyed" << std::endl;
}
