/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:49:51 by pjay              #+#    #+#             */
/*   Updated: 2023/05/05 15:00:07 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." <<std::endl;
}
void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string tab[4] = {"info", "debug", "warning", "error"};
	void	(Harl::*functionPtr[4])(void) = {&Harl::info, &Harl::debug, &Harl::warning, &Harl::error};
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tab[i] == level)
		{
			(this->*functionPtr[i])();
			return ;
		}
		i++;
	}
	std::cout << "this key doesnt exist" << std::endl;
}
