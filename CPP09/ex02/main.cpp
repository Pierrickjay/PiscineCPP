/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:51:59 by pjay              #+#    #+#             */
/*   Updated: 2023/08/07 15:43:10 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int checkArgs(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		std::string str = av[i];
		for (size_t a = 0; a < str.length(); a++)
		{
			if (!isdigit(str[a]))
			{
				BAD_PARAM
				return (-1);
			}
		}
		if (atoi(str.c_str()) <= 0)
			return (-1);
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac <= 1 || checkArgs(av) == -1)
	{
		BAD_PARAM
		return (1);
	}
	PmergeMe(av, ac - 1);
}

