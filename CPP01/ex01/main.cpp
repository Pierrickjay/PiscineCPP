/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:45:15 by pjay              #+#    #+#             */
/*   Updated: 2023/04/21 10:04:54 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	print_name(Zombie *Horde, int N)
{
	int i;

	i = 0;
	while(i < N)
	{
		Horde[i].announce();
		i++;
	}
}

int main()
{
	Zombie *Horde;
	Zombie *Horde2;

	Horde = zombieHorde(10, "The most handsome"); // creation de la horde de 10 zombies
	print_name(Horde, 10); // printing the name
	delete [] Horde;
	Horde2 = zombieHorde(10, "The most UgglyOne");
	print_name(Horde2, 10);
	delete [] Horde2;
	return 0;
}
