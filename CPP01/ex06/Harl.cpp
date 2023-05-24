/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:49:51 by pjay              #+#    #+#             */
/*   Updated: 2023/05/06 14:31:06 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl << std::endl;
}
void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl<< std::endl;
}
void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." <<std::endl<< std::endl;
}
void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." <<std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl<< std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	tab[4] = {"INFO", "DEBUG", "WARNING", "ERROR"};
	void		(Harl::*functionPtr[4])(void) = {&Harl::info, &Harl::debug, &Harl::warning, &Harl::error};
	int			i = 0;
	bool		exist = false;
	std::string change = level;

	while (i < 4)
	{
		if (tab[i] == level)
			exist = true;
		i++;
	}
	if (exist == false)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}
	i = 0;
	while (i < 4)
	{
		if (tab[i] == change)
		{
			switch ((tab[i][0]))
			{
				case 'I' :
				{
					std::cout << "[ INFO ]" << std::endl;
					(this->*functionPtr[i])();
					change = "WARNING";
					i = -1;
					//it = func.find("WARNING");
					break;
				}
				case 'D' :
				{
					std::cout << "[ DEBUG ]" << std::endl;
					(this->*functionPtr[i])();;
					i = -1;
					change = "INFO";
					break;
				}
				case 'W' :
				{
					std::cout << "[ WARNING ]" << std::endl;
					(this->*functionPtr[i])();;
					i = -1;
					change = "ERROR";
					break;
				}
				case 'E' :
				{
					std::cout << "[ ERROR ]" << std::endl;
					(this->*functionPtr[i])();
					return ;
				}
			}
		}
		i++;
	}
}
