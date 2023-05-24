/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:51:34 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 09:17:28 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap leo("Leonard");
	FragTrap val("Valentin");
	FragTrap theo;
	FragTrap hugo("Hugo");
	ClapTrap David("David");
	ClapTrap Lucas("Lucas");
	theo.attack("Valentin");
	David.attack("Alix");
	Lucas = David;
	val.attack("Valentin");
	theo.HighFivesGuys();
	hugo.HighFivesGuys();
	leo.attack("Alan");
	leo.takeDamage(5);
	leo.takeDamage(2);
	val = leo;
	val.attack("Axel");
	val.beRepaired(7);
}
