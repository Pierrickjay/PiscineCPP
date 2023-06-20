/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:33:57 by pjay              #+#    #+#             */
/*   Updated: 2023/05/31 17:29:36 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	#ifdef DEBUG
	std::cout << RED "Constructor of Intern Called" RESET << std::endl;
	#endif
}

Intern::Intern(const Intern& rhs)
{
	(void)rhs;
	#ifdef DEBUG
	std::cout << RED "Constructor of Intern Called" RESET << std::endl;
	#endif
}

Intern Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return (*this);
	#ifdef DEBUG
	std::cout << RED "Constructor of Intern Called" RESET << std::endl;
	#endif
}

Intern::~Intern()
{
	#ifdef DEBUG
	std::cout << RED "Constructor of Intern Called" RESET << std::endl;
	#endif
}

const char* Intern::FormDoesntExist::what () const throw()
{
	return ("Intern::CannotCreateThisForm");

}
AForm *Intern::makeForm(std::string nameOfForm, std::string target)
{
	std::string tab[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (int i = 0; i < 3; i++)
	{
		if (tab[i] == nameOfForm)
		{
			switch (tab[i][0])
			{
				case 'p' :
				{
					AForm *presi = new PresidentialPardonForm(target);
					return (presi);
				}
				case 'r' :
				{
					AForm *robot = new RobotomyRequestForm(target);
					return (robot);
				}
				case 's' :
				{
					AForm *shrub = new ShrubberyCreationForm(target);
					return (shrub);
				}
			}
		}
	}
	std::cout << "This " << nameOfForm << " of form doesn't exist " << std::endl;
	throw FormDoesntExist();
	return (NULL);
}

