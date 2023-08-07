/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:25:35 by pjay              #+#    #+#             */
/*   Updated: 2023/08/05 10:27:18 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Number.hpp"

Number::Number()
{
	#ifdef DEBUG
		std::cout << "Constructor of Number called" << std::endl;
	#endif
}

Number::Number(const Number& rhs)
{
	_n = rhs._n;
	_indPair = rhs._indPair;
	#ifdef DEBUG
		std::cout << "Constructor by assignement of Number called" << std::endl;
	#endif
}

Number& Number::operator=(const Number& rhs)
{
	#ifdef DEBUG
		std::cout << "Constructor by operator of Number called" << std::endl;
	#endif
	if (this != &rhs)
	{
		_n = rhs._n;
		_indPair = rhs._indPair;
	}
	return (*this);
}

Number::~Number()
{
	#ifdef DEBUG
		std::cout << "Destructor of Number called" << std::endl;
	#endif
}

// void Number::setIndPair(unsigned int indPair)
// {
// 	_indPair = indPair;
// }

unsigned int Number::getIndPair() const
{
	return (_indPair);
}

Number::Number(int n, unsigned int indPair)
{
	_n = n;
	_indPair = indPair;
}

int Number::getNumb() const
{
	return (_n);
}

bool Number::operator<(const Number& rhs) const
{
	return (_n < rhs._n);
}

bool Number::operator>(const Number& rhs) const
{
	return (_n > rhs._n);
}
