/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:03:00 by pjay              #+#    #+#             */
/*   Updated: 2023/05/31 17:27:42 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		ShrubberyCreationForm test;
		ShrubberyCreationForm tree("the forest");
		RobotomyRequestForm robot3;
		RobotomyRequestForm telephone("Wall-E");
		PresidentialPardonForm dimanche;
		PresidentialPardonForm Theboys("Hughie");
		//AForm tessss;
		Bureaucrat Alan(1, "Alan");
		Bureaucrat Jul(71, "La Poste");
		Alan.executeForm(Theboys);
		Alan.signForm(Theboys);
		Alan.executeForm(Theboys);
		Jul.signForm(telephone);
		Jul.executeForm(telephone);
		Alan.executeForm(telephone);
		Jul.signForm(dimanche);
		Alan.signForm(tree);
		Alan.executeForm(tree);
		Alan.signForm(test);
		Alan.executeForm(test);
		std::cout << std::endl << std::endl;
		std::cout << tree << std::endl;
		std::cout << telephone << std::endl;
		std::cout << Theboys << std::endl;
		std::cout << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


}
