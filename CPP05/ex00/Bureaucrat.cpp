/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:41:24 by pjay              #+#    #+#             */
/*   Updated: 2023/05/23 14:41:24 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucat.hpp"


Bureaucrat::Bureaucrat() : _name("default")
{
	std::cout << "Default Constructor of Bureaucrat Called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name)
{
	
	std::cout << "Constructor of Bureaucrat Called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor of Bureaucrat Called" << std::endl;
}

std::string Bureaucrat::getName()
{
	return (_name);

}

int Bureaucrat::getGrade()
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{

}

void Bureaucrat::decrementGrade()
{

}


