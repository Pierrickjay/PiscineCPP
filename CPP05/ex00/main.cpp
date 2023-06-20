/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:22:14 by pjay              #+#    #+#             */
/*   Updated: 2023/05/31 17:08:19 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{

	try
	{
		Bureaucrat Xavier(1, "Niel");
		Bureaucrat Jul(75, "DTP");
		Bureaucrat Rien;

		std::cout << Rien << std::endl;
		Rien = Jul;
		std::cout << Rien << std::endl;
		Bureaucrat JulCopy(Jul);
		Bureaucrat Paul(200, "Bocuse");
		//Bureaucrat test(-2, "Looser");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Xavier(1, "Niel");
		Xavier.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Loic(150, "Inconnue");
		Loic.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Jul(75, "DTP");
		Bureaucrat JulCopy(Jul);
		std::cout << Jul << std::endl;
		Jul.decrementGrade();
		std::cout << Jul << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
