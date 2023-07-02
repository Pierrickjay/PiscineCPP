/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:20:24 by pjay              #+#    #+#             */
/*   Updated: 2023/06/23 21:20:24 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
Rpn::Rpn(char *av)
{
	_str = av;
	#ifdef DEBUG
		std::cout << "Constructor of rpn called" << std::endl;
	#endif
}

int Rpn::checkIt()
{
	for (size_t i = 0; i < _str.length(); i++)
	{
		std::cout << _str[i] << std::endl;
		if (!isdigit(_str[i]))
		{
			if (_str[i] != ' ' &&_str[i] != '+' && _str[i] != '-' && _str[i] != '*' && _str[i] != '/')
				return (-1);
		}
		else
		{
			std::cout << "enter here" << std::endl;
			_filo.push(_str[i] - '0');
		}
	}
	return (0);
}

int Rpn::calcIt()
{
	int total = _filo.top();
	std::cout << "stack size is " << _filo.size() << std::endl;
	_filo.pop();

	for (size_t i = 0; i < _str.length(); i++)
	{
		std::cout << " total is " << total << std::endl;
		if ((_str[i] == '+' || _str[i] == '-' || _str[i] == '*' || _str[i] == '/' ) && !_filo.empty())
		{
			std::cout << "enter here when str[i] = " << _str[i] << std::endl;
			switch (_str[i])
			{
				case '-' :
					total = total - _filo.top();
					break ;
				case '+' :
					total = total + _filo.top();
					break ;
				case '*' :
					total = total + _filo.top();
					break ;
				default :
					total = total / _filo.top();
					break ;
			}
			_filo.pop();
		}

	}
	return (total);
}

