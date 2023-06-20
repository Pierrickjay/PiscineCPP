/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:21:51 by pjay              #+#    #+#             */
/*   Updated: 2023/05/30 13:56:31 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm() : _name("Useless AForm"), _gradeToSigned(150), _gradeToExecuted(150)
{
	_signed = false;
	std::cout << GREEN "default Constructor of AForm Called" RESET << std::endl;
}

AForm::AForm(const AForm& rhs) :_name (rhs._name),  _gradeToSigned(rhs._gradeToSigned) ,_gradeToExecuted(rhs._gradeToExecuted)
{
	_signed = false;
	std::cout << GREEN "Constructor by assignement of AForm Called" RESET << std::endl;
}

AForm& AForm::operator= (const AForm& rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	std::cout << GREEN "Operator = of AForm Called" RESET << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << GREEN "destructor of AForm Called" RESET << std::endl;
}

AForm::AForm(std::string name, int gradeToSigned, int gradeToExecuted) : _name(name), _gradeToSigned(gradeToSigned), _gradeToExecuted(gradeToExecuted)
{
	if (_gradeToExecuted > 150 || _gradeToSigned > 150)
		throw GradeTooLowException();
	if (_gradeToExecuted < 0 || _gradeToSigned < 0)
		throw GradeTooHighException();
	_signed = false;
	std::cout << GREEN "default Constructor of AForm Called" RESET << std::endl;
}

int AForm::getGradeToSigned() const
{
	return (_gradeToSigned);
}

int AForm::getGradeToExecuted() const
{
	return (_gradeToExecuted);
}

bool AForm::getSigned() const
{
	return (_signed);
}

std::string AForm::getName() const
{
	return (_name);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}

const char* AForm::NotSigned::what() const throw()
{
	return ("Form::AFormNeedToBeSignedToBeExecutedException");
}

void AForm::beSigned(Bureaucrat &bureaucrat)
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

void AForm::execute(Bureaucrat const &executor) const
{
		if (_signed == false)
			throw NotSigned();
		if (executor.getGrade() > _gradeToExecuted)
			throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& file, const AForm& aform)
{
	file << "form's Name : " << aform.getName() << "| Signed : " << (aform.getSigned() ? "true" : "false");
	file << "| Grade to be Signed : " << aform.getGradeToSigned() << "| Grade to be executed " << aform.getGradeToExecuted();
	return file;
}
