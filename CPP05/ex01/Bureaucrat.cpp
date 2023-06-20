/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:41:24 by pjay              #+#    #+#             */
/*   Updated: 2023/05/31 15:44:15 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name)
{

	if (grade < 0)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Constructor of Bureaucrat Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : _name(bureaucrat._name)
{
	_grade = bureaucrat._grade;
	std::cout << BLUE "Constructor of assignement Bureaucrat called" RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& bureaucrat)
{
	std::cout << BLUE "Constructor of assignment operator of Bureaucrat called" RESET << std::endl;
	if (this != &bureaucrat)
	{

		_grade = bureaucrat._grade;
	}
	return *this;
}
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{

	std::cout << BLUE "Constructor of Bureaucrat called" RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor of Bureaucrat Called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	else
	{
		std::cout << _name << " have been increment" << std::endl;
		_grade = _grade - 1;
	}
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	else
	{
		std::cout << _name << " have been decrement" << std::endl;
		_grade = _grade + 1;
	}
}

std::ostream& operator<<(std::ostream& file, const Bureaucrat& bureaucrat)
{
	file << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade();
	return file;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

void Bureaucrat::signForm(Form& form)
{
	if (form.getSigned() == false)
	{
		try
		{
			form.beSigned(*this);
			std::cout << *this << " signed " << form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << _name << " couldn't sign " << form.getName() << " because ";
			std::cerr << e.what() << std::endl;
		}
	}
	else
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because it's already sign" << std::endl;
	}
	//<bureaucrat> couldn’t sign <form> because <reason>.

}
