/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:45:15 by pjay              #+#    #+#             */
/*   Updated: 2023/05/08 10:55:54 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *ugglyOne;
	Zombie *prettyOne;
	std::cout << "let's make an army of Zombie!!" << std::endl;
	randomChump("HorribleZombie"); // allocated just inside the function
	ugglyOne = newZombie("ugglyOne"); // allocated dynamically to be used outside the function
	ugglyOne->announce();
	randomChump("StandardZombie"); // allocated just inside the function
	prettyOne = newZombie("prettyOne"); // allocated dynamically to be used outside the function
	prettyOne->announce();
	delete ugglyOne;
	delete prettyOne;
	return 0;
}
