/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:28:07 by pjay              #+#    #+#             */
/*   Updated: 2023/05/23 14:28:07 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int			_grade;
	public:
		Bureaucrat();
		Bureaucrat(int grade, std::string name);
		~Bureaucrat();
		std::string getName();
		void incrementGrade();
		void decrementGrade();
		int getGrade();
};

std::ostream& operator<<(std::ostream& file, const Bureaucrat& bureaucrat);
