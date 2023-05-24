/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:46:27 by pjay              #+#    #+#             */
/*   Updated: 2023/05/08 10:57:11 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie ::Zombie(void)
{
	std::cout << "Constructor called" << std::endl;
}

void Zombie::setName(std::string name)
{
	std::cout << "Constructor called" << std::endl;
	_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor called" << std::endl;
	std::cout << _name << " horde deleted" << std::endl;
}
