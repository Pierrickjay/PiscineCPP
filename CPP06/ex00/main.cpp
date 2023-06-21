/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:00:15 by pjay              #+#    #+#             */
/*   Updated: 2023/06/21 12:48:34 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
// You have to handle these pseudo literals as well (you know, for science): -inff, +inff
// and nanf.
int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please enter only one parametter after the programs name" << std::endl;
		return (1);
	}
	ScalarConverter convert;
	convert.convert(av[1]);
	//convert.convert(av[1]);

}
