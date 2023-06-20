/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:43:35 by pjay              #+#    #+#             */
/*   Updated: 2023/05/31 17:31:44 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137)
{
	_target = "default";
	std::cout << RED "Constructor of ShrubberyCreationForm called" RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm("ShrubberyCreation", 145, 137)
{
	_target = rhs._target;
	std::cout << RED "Constructor of ShrubberyCreationForm called" RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& rhs)
{
	std::cout << RED "Constructor of ShrubberyCreationForm called" RESET << std::endl;
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED "Destructor of ShrubberyCreationForm called" RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137)
{
	_target = target;
	std::cout << RED "Constructor of ShrubberyCreationForm called" RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw NotSigned();
	if (executor.getGrade() > this->getGradeToExecuted())
		throw GradeTooLowException();
	std::string test(_target + "_shruberry");
	std::ofstream file2(test.c_str());
	if (!file2.is_open())
		std::cout << "unable to open file" << std::endl;
	else
	{
		file2 << "               ,@@@@@@@,\n       ,,,.   ,@@@@@@/@@,  .oo8888o.\n    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o " << std::endl;
		file2 << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		file2 << "   `&%\\ ` /%&'    |.|        \\ '|8'\n       |o|        | |         | |\n       |.|        | |         | |\n    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	}
}
