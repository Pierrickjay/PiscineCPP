/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:25:59 by pjay              #+#    #+#             */
/*   Updated: 2023/07/10 14:39:32 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span()
{
	#ifdef DEBUG
		std::cout << RED"Constructor of Span Called"RESET << std::endl;
	#endif
}

Span::Span(const Span& rhs)
{
	#ifdef DEBUG
	std::cout << RED"Constructor by assignement of Span Called"RESET << std::endl;
	#endif
	for (std::vector<int>::const_iterator it = rhs._vec.begin(); it < rhs._vec.end() ; it++)
	{
		_vec.push_back(*it);
	}
	_size = rhs._size;
}

Span& Span::operator=(const Span& rhs)
{
	#ifdef DEBUG
	std::cout << RED"Constructor by operator of Span Called"RESET << std::endl;
	#endif
	if (this != &rhs)
	{
		_vec.clear();
		for (std::vector<int>::const_iterator it = rhs._vec.begin(); it < rhs._vec.end() ; it++)
		{
			_vec.push_back(*it);
		}
		_size = rhs._size;
	}
	return *this;
}

Span::~Span()
{
	_vec.clear();
	#ifdef DEBUG
	std::cout << RED"Destructor of Span Called"RESET << std::endl;
	#endif
}

Span::Span(unsigned int N)
{
	_size = N;
	#ifdef DEBUG
	std::cout << RED"Constructor of Span Called"RESET << std::endl;
	#endif
}

void Span::addNumber(int N)
{
	if (_vec.size() ==  _size)
		throw SpanFull();
	else
		_vec.push_back(N);
}

int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw NoNumber();
	Span cpy(*this);
	int test;
	std::sort(cpy._vec.begin(), cpy._vec.end());
	int minDiff = cpy._vec[1] - cpy._vec[0];
	test = cpy._vec[1];
	for (std::vector<int>::iterator it = cpy._vec.begin() + 2; it < cpy._vec.end(); it++)
	{
		minDiff = std::min(minDiff, *it - test);
		test = *it;
	}
	return (std::abs(minDiff));
}

int Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw NoNumber();
	std::vector<int>::iterator biggest = _vec.begin();
	std::vector<int>::iterator shortest = _vec.begin();
	for (std::vector<int>::iterator it = _vec.begin(); it < _vec.end(); it++)
	{
		if (*it > *biggest)
			biggest = it;
		if (*it < *shortest)
			shortest = it;
	}
	return (std::abs(*biggest - *shortest));
}

void Span::addMultiNumber(std::vector<int> toAdd)
{
	if (_vec.size() + std::distance(toAdd.begin(), toAdd.end()) > _size)
		throw SpanFull();
	_vec.insert(_vec.end(), toAdd.begin(), toAdd.end());
}

void Span::addMultiNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vec.size() + std::distance(begin, end) > _size)
		throw SpanFull();
	_vec.insert(_vec.end(), begin, end);
}

void Span::printSpan()
{
	for (std::vector<int>::iterator it = _vec.begin() ; it < _vec.end(); it++)
		std::cout << *it << std::endl;
}

const char* Span::SpanFull::what() const throw()
{
	return ("Can't add another element SpanFull");
}

const char* Span::NoNumber::what() const throw()
{
	return ("Not enough number stored to found longest or shortest Span");
}

