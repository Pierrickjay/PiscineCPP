/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:33:42 by pjay              #+#    #+#             */
/*   Updated: 2023/05/31 16:47:47 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &rhs);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs);
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		void execute(Bureaucrat const &executor) const;
};
