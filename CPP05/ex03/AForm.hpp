/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:22:04 by pjay              #+#    #+#             */
/*   Updated: 2023/05/31 16:10:46 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "color.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private :
		const std::string _name;
		bool	_signed;
		const int _gradeToSigned;
		const int _gradeToExecuted;
	public :
		AForm();
		AForm(const AForm& rhs);
		AForm& operator= (const AForm& rhs);
		virtual ~AForm();
		int getGradeToSigned() const;
		int getGradeToExecuted() const;
		bool getSigned() const;
		std::string getName() const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
		AForm(std::string name, int gradeToSigned, int gradeToExecuted);
		class GradeTooLowException : public std::exception
		{
			public:
  				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
  				virtual const char* what() const throw();
		};
		class NotSigned : public std::exception
		{
			public:
  				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& file, const AForm& AForm);
