/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:20:24 by pjay              #+#    #+#             */
/*   Updated: 2023/07/03 10:59:22 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	#ifdef DEBUG
		std::cout << "Constructor of RPN called" << std::endl;
	#endif
}

RPN::RPN(const RPN &rhs)
{
	*this = rhs;
	#ifdef DEBUG
		std::cout << "Constructor of RPN called" << std::endl;
	#endif

}

RPN& RPN::operator=(const RPN &rhs)
{
	_str = rhs._str;
	_filo = rhs._filo;
	#ifdef DEBUG
		std::cout << "Constructor of RPN called" << std::endl;
	#endif
	return (*this);
}

RPN::~RPN()
{
	#ifdef DEBUG
		std::cout << "Constructor of RPN called" << std::endl;
	#endif
}

RPN::RPN(char *av)
{
	_str = av;
	#ifdef DEBUG
		std::cout << "Constructor of RPN called" << std::endl;
	#endif
}

int RPN::checkIt()
{
	for (size_t i = 0; i < _str.length(); i++)
	{
		if (!isdigit(_str[i]))
		{
			if (_str[i] != ' ' &&_str[i] != '+' && _str[i] != '-' && _str[i] != '*' && _str[i] != '/')
				return (-1);
			if (_str[i] != ' ' && _str[i + 1] && _str[i + 1] != ' ')
				return (-1);
			if (!_str[i + 1] && _str[i] != '+' && _str[i] != '-' && _str[i] != '*' && _str[i] != '/')
				return (-1);
		}
		else
		{
			if (!_str[i + 1])
				return (-1);
			if (_str[i + 1] && _str[i + 1] != ' ')
				return (-1);
		}
	}
	return (0);
}

int RPN::calcIt()
{
	int total;
	bool totfill = false;

	for (size_t i = 0; i < _str.length(); i++)
	{
		if ((_str[i] == '+' || _str[i] == '-' || _str[i] == '*' || _str[i] == '/' ) && !_filo.empty())
		{
			switch (_str[i])
			{
				case '-' :
					total = total - _filo.top();
					break ;
				case '+' :
					total = total + _filo.top();
					break ;
				case '*' :
					total = total * _filo.top();
					break ;
				default :
					total = total / _filo.top();
					break ;
			}
			_filo.pop();
		}
		else if (isdigit(_str[i]))
		{
			if (i == 0 || (i == 2 && totfill != true))
			{
				total = _str[i] - '0';
				totfill = true;
			}
			else
			{
				_filo.push(_str[i] - '0');
				totfill = true;
			}
		}
	}
	return (total);
}

