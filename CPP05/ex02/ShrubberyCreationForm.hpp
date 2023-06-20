/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:33:22 by pjay              #+#    #+#             */
/*   Updated: 2023/05/31 16:47:38 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"
#include "color.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private :
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& rhs);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		void execute(Bureaucrat const &executor) const;
};
