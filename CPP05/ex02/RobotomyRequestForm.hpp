/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:53:18 by pjay              #+#    #+#             */
/*   Updated: 2023/05/31 17:17:13 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private :
		std::string _target;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &rhs);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs);
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		void execute(Bureaucrat const &executor) const;
};
