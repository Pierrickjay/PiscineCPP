/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:41:48 by pjay              #+#    #+#             */
/*   Updated: 2023/05/22 13:38:10 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cout << CYAN"Constructor of Character Called" RESET << std::endl;
}
Character::Character(const Character& character)
{
	std::cout << CYAN"Constructor copy of Character Called" RESET << std::endl;
}
Character& Character::operator =(const Character& character)
{
	std::cout << CYAN"Constructor copy assignement of Character Called" RESET << std::endl;
}
Character::~Character(void)
{
	std::cout << CYAN"destructor of Character Called" RESET << std::endl;
}
