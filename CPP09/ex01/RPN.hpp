/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:14:20 by pjay              #+#    #+#             */
/*   Updated: 2023/07/03 10:59:03 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

class RPN
{
	private :
		std::string _str;
		std::stack<int> _filo;
	public :
		RPN();
		RPN(const RPN &rhs);
		RPN& operator=(const RPN &rhs);
		~RPN();
		RPN(char *av);
		int checkIt();
		int calcIt();
};
