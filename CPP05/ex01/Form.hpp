/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:22:04 by pjay              #+#    #+#             */
/*   Updated: 2023/05/26 11:31:09 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "color.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		const std::string _name;
		bool	_signed;
		const int _gradeToSigned;
		const int _gradeToExecuted;
	public :
		Form();
		Form(const Form& form);
		Form& operator= (const Form& form);
		~Form();
		int getGradeToSigned() const;
		int getGradeToExecuted() const;
		bool getSigned() const;
		std::string getName() const;
		void beSigned(Bureaucrat &bureaucrat);
		Form(std::string name, int gradeToSigned, int gradeToExecuted);

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
};

std::ostream& operator<<(std::ostream& file, const Form& form);
