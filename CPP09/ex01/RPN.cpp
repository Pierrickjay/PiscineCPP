/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:20:24 by pjay              #+#    #+#             */
/*   Updated: 2023/08/11 14:05:18 by pjay             ###   ########.fr       */
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
	int countSign = 0;
	int countNumber = 0;
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
			if (_str[i] == '+' || _str[i] == '-' || _str[i] == '*' || _str[i] == '/')
				countSign++;
		}
		else
		{
			if (!_str[i + 1])
				return (-1);
			if (_str[i + 1] && _str[i + 1] != ' ')
				return (-1);
			countNumber++;
		}
	}
	if (countNumber - countSign != 1)
		return (-1);
	return (0);
}

int RPN::calcIt()
{
	size_t spaceLen = 0;
	size_t i = 0;
	while (_str[spaceLen] == ' ')
		spaceLen++;
	while (i + spaceLen < _str.length())
	{
		int left = 0;
		int right = 0;
		if ((_str[i + spaceLen] == '+' || _str[i + spaceLen] == '-' || _str[i + spaceLen] == '*' || _str[i + spaceLen] == '/' ))
		{
			if (_filo.empty())
			{
				std::cout << "Bad implementation" << std::endl;
				return (-1);
			}

			switch (_str[i + spaceLen])
			{
				case '-' :
					left = _filo.top();
					_filo.pop();
					right = _filo.top();
					_filo.pop();
					_filo.push(right - left);
					break ;
				case '+' :
					left = _filo.top();
					_filo.pop();
					right = _filo.top();
					_filo.pop();
					_filo.push(right + left);
					break ;
				case '*' :
					left = _filo.top();
					_filo.pop();
					right = _filo.top();
					_filo.pop();
					_filo.push(right * left);
					break ;
				default :
					left = _filo.top();
					_filo.pop();
					right = _filo.top();
					_filo.pop();
					if (left == 0 || right == 0)
					{
						std::cout << "Cannot divide by 0" << std::endl;
						return (-1);
					}
					_filo.push(right / left);
					break ;
			}
		}
		else if (isdigit(_str[i + spaceLen]))
		{
			_filo.push(_str[i + spaceLen] - '0');
		}
		i++;
	}
	std::cout << "Result = " << _filo.top() << std::endl;
	return (_filo.top());
}

