/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:03:00 by pjay              #+#    #+#             */
/*   Updated: 2023/05/31 17:41:00 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat Alan(6, "Alan");
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Alan.signForm(*rrf);
		std::cout << *rrf << std::endl;
		Alan.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		Alan.signForm(*rrf);
		std::cout << *rrf << std::endl;
		Alan.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		Alan.signForm(*rrf);
		std::cout << *rrf << std::endl;
		Alan.executeForm(*rrf);
		Alan.incrementGrade();
		Alan.incrementGrade();
		Alan.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("eeee", "eeeee");
		Alan.executeForm(*rrf);
		Alan.signForm(*rrf);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
