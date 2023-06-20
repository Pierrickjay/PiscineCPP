/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:22:14 by pjay              #+#    #+#             */
/*   Updated: 2023/05/30 13:51:39 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Form ImpossibleOne("fail", 50, 190);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form ImpossibleOne("fail", -1, 80);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Xavier(1, "Niel");
		Bureaucrat Loic(150, "La Poste");
		Form Decla("Declaration Des Droits de l'Homme", 1, 1);
		Form easy;
		std::cout << Decla << std::endl;
		std::cout << easy << std::endl;
		std::cout << Loic << std::endl;
		std::cout << Loic.getName() << " try to sign the decla" << std::endl;
		Loic.signForm(Decla);
		std::cout << Loic.getName() << " try to sign easy" << std::endl;
		Loic.signForm(easy);
		std::cout << easy << std::endl;
		std::cout << Xavier << std::endl;
		std::cout << Xavier.getName() << " try to sign the decla" << std::endl;
		Xavier.signForm(Decla);
		std::cout << Decla << std::endl;
		Xavier.signForm(Decla);
		std::cout << Decla << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
