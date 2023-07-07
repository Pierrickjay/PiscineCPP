/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:15:43 by pjay              #+#    #+#             */
/*   Updated: 2023/07/03 10:31:01 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "please enter only one string" << std::endl;
		return (0);
	}
	RPN polish(av[1]);
	if (polish.checkIt() == -1)
	{
		std::cout << "please enter a valid reverse polish notation" <<std::endl;
		return (0);
	}
	std::cout << "Result is " << polish.calcIt() << std::endl;
}
