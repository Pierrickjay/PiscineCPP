/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:14:20 by pjay              #+#    #+#             */
/*   Updated: 2023/06/23 21:14:20 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

class Rpn
{
	private :
		std::string _str;
		std::stack<int> _filo;
	public :
		Rpn(char *av);
		int checkIt();
		int calcIt();
};
