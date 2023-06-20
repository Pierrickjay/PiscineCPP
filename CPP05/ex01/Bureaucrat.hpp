/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:28:07 by pjay              #+#    #+#             */
/*   Updated: 2023/05/26 11:31:49 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "color.hpp"
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int			_grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& bureaucrat);
		Bureaucrat& operator= (const Bureaucrat& bureaucrat);
		~Bureaucrat();
		Bureaucrat(int grade, std::string name);
		void incrementGrade();
		void decrementGrade();
		std::string getName() const;
		int getGrade() const;
		void signForm(Form& form);

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

std::ostream& operator<<(std::ostream& file, const Bureaucrat& bureaucrat);
