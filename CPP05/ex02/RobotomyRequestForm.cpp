/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:56:51 by pjay              #+#    #+#             */
/*   Updated: 2023/05/31 17:17:46 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << MAGENTA "Constructor of Robotomy Request Form" RESET << std::endl;
	_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = rhs._target;
	std::cout << MAGENTA "Constructor of Robotomy Request Form by assignement called" RESET << std::endl;

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << MAGENTA "Constructor of Robotomy Request Form" RESET << std::endl;
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << MAGENTA "Destructor of Robotomy Request Form" RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
	std::cout << MAGENTA "Constructor of Robotomy Request Form called" RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw NotSigned();
	if (executor.getGrade() > this->getGradeToExecuted())
		throw GradeTooLowException();
	std::cout << "Making some drilling noises | ";
	std::srand(time(NULL));
	int a = std::rand() % 10 + 1;
	if (a % 2 == 0)
		std::cout << _target << " target has been robotomized" << std::endl;
	else
		std::cout << _target << " target robotomy failed" << std::endl;
}
