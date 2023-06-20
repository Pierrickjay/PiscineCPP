/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:35:50 by pjay              #+#    #+#             */
/*   Updated: 2023/05/31 17:40:23 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << YELLOW "Constructor of PresidentialPardonForm Called" RESET<< std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs)  : AForm("PresidentialPardonForm", 25, 5)
{
	_target = rhs._target;
	std::cout << YELLOW "Constructor of PresidentialPardonForm Called" RESET<< std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << YELLOW "Destructor of PresidentialPardonForm Called" RESET<< std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target)  : AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
	std::cout << YELLOW "Constructor of PresidentialPardonForm Called" RESET<< std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw NotSigned();
	if (executor.getGrade() > this->getGradeToExecuted())
		throw GradeTooLowException();
	//std::cout << " grade = "  << executor.getGrade()<< " exec " <<  this->getGradeToExecuted() << std::endl;
	std::cout << _target << " have been pardoned by Zaphod Beeblebrox" << std::endl;
}
