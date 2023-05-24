/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:51:34 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 08:55:12 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap leo("Leonard");
	ClapTrap val("Valentin");
	ClapTrap theo;
	theo.attack("Valentin");
	val.attack("Valentin");
	val.attack("Valentin");
	val.attack("Valentin");
	val.attack("Valentin");
	val.attack("Valentin");
	val.attack("Valentin");
	val.attack("Valentin");
	val.attack("Valentin");
	val.attack("Valentin");
	val.attack("Valentin");
	val.attack("Valentin");
	leo.attack("Alan");
	leo.takeDamage(5);
	leo.takeDamage(2);
	leo.takeDamage(3);
	leo.beRepaired(2);
	val = leo;
	val.attack("Axel");
	val.beRepaired(7);
}
