/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:51:34 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 09:14:34 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap leo("Leonard");
	ScavTrap val("Valentin");
	ScavTrap theo;
	ClapTrap David("David");
	ClapTrap Lucas("Lucas");
	theo.attack("Valentin");
	David.attack("Alix");
	leo.guardGate();
	Lucas = David;
	David.attack("Quelqu'un");
	val.attack("Valentin");
	leo.attack("Alan");
	leo.takeDamage(5);
	leo.takeDamage(2);
	val = leo;
	val.attack("Axel");
	val.beRepaired(7);
}
