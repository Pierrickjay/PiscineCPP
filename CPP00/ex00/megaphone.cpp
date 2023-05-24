/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:19:48 by pjay              #+#    #+#             */
/*   Updated: 2023/04/03 15:34:44 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

bool checkIfAllEmpty(int ac, char **av)
{
	int i = 1;

	while (i < ac -1)
	{
		if (!(av[i][0] == '\0'))
			return (false);
		i++;
	}
	return (true);
}

int main(int ac, char **av)
{
	char x;
	if (ac == 1 || checkIfAllEmpty(ac, av) == true)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" << std::endl;
	else
	{
		for (int i = 1; av[i]; i++)
		{
			for (int j = 0; av[i][j]; j++)
			{
				if (islower(av[i][j]))
					x = av[i][j] - 32;
				else
					x = av[i][j];
				std::cout << x;
			}
		}
		std::cout << std::endl;
	}
}
