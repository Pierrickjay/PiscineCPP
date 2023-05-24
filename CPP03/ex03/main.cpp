/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:51:34 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 11:41:19 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	//FragTrap leo("Leonard");
	// ClapTrap David("David");
	//ScavTrap val;
	DiamondTrap alan("Alan");
	DiamondTrap jul;
	DiamondTrap pasteque(alan);
	// David.attack("Alix");
	// val.attack("Valentin");
	// leo.HighFivesGuys();
	//leo.attack("Alan");
	// leo.takeDamage(5);
	// leo.takeDamage(2);
	// val.attack("Axel");
	// val.beRepaired(7);
	jul = alan;
	alan.whoAmI();
	pasteque.whoAmI();
	jul.attack("Julien");
	alan.attack("Julien");
	alan.beRepaired(8);
	alan.guardGate();
	alan.HighFivesGuys();
	alan.takeDamage(50);
	alan.takeDamage(50);
	alan.beRepaired(50);
}
