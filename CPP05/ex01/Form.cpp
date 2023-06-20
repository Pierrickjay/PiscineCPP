/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:21:51 by pjay              #+#    #+#             */
/*   Updated: 2023/05/30 13:44:22 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Useless Form"), _gradeToSigned(150), _gradeToExecuted(150)
{
	_signed = false;
	std::cout << GREEN "default Constructor of Form Called" RESET << std::endl;
}

Form::Form(const Form& form) :_name (form._name),  _gradeToSigned(form._gradeToSigned) ,_gradeToExecuted(form._gradeToExecuted)
{
	_signed = false;
	std::cout << GREEN "Constructor by assignement of Form Called" RESET << std::endl;
}

Form& Form::operator= (const Form& form)
{
	if (this != &form)
		_signed = form._signed;
	std::cout << GREEN "Operator = of Form Called" RESET << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << GREEN "destructor of Form Called" RESET << std::endl;
}

Form::Form(std::string name, int gradeToSigned, int gradeToExecuted) : _name(name), _gradeToSigned(gradeToSigned), _gradeToExecuted(gradeToExecuted)
{
	if (_gradeToExecuted > 150 || _gradeToSigned > 150)
		throw GradeTooLowException();
	if (_gradeToExecuted < 0 || _gradeToSigned < 0)
		throw GradeTooHighException();
	_signed = false;
	std::cout << GREEN "default Constructor of Form Called" RESET << std::endl;
}

int Form::getGradeToSigned() const
{
	return (_gradeToSigned);
}

int Form::getGradeToExecuted() const
{
	return (_gradeToExecuted);
}

bool Form::getSigned() const
{
	return (_signed);
}

std::string Form::getName() const
{
	return (_name);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSigned)
	{
		_signed = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& file, const Form& form)
{
	file << "Form's Name : " << form.getName() << "| Signed : " << (form.getSigned() ? "true" : "false");
	file << "| Grade to be Signed : " << form.getGradeToSigned() << "| Grade to be executed " << form.getGradeToExecuted();
	return file;
}
