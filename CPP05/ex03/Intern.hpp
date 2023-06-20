/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:34:49 by pjay              #+#    #+#             */
/*   Updated: 2023/05/30 14:30:28 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

class Intern
{
	public :
		Intern();
		Intern(const Intern& rhs);
		Intern operator=(const Intern& rhs);
		~Intern();
		AForm *makeForm(std::string nameOfform, std::string target);
		class FormDoesntExist : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
