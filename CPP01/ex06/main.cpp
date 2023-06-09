/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:54:30 by pjay              #+#    #+#             */
/*   Updated: 2023/05/06 14:33:04 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl name;

	if (ac != 2)
	{
		std::cout << "ERROR" << std::endl;
	}
	else
		name.complain(av[1]);
}
