/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:25:59 by pjay              #+#    #+#             */
/*   Updated: 2023/06/20 12:26:15 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span()
{
	std::cout << RED"Constructor of Span Called"RESET << std::endl;
}

Span::Span(const Span& rhs)
{
	std::cout << RED"Constructor by assignement of Span Called"RESET << std::endl;
	for (unsigned int i = 0; i < rhs._size; i++)
	{
		_vec.push_back(rhs.findpos(i));
	}
	_size = rhs._size;
}

Span& Span::operator=(const Span& rhs)
{
	std::cout << RED"Constructor by operator of Span Called"RESET << std::endl;
	if (this != &rhs)
	{
		_vec.clear();
		for (unsigned int i = 0; i < rhs._size; i++)
		{
			_vec.push_back(rhs.findpos(i));
		}
		_size = rhs._size;
	}
	return *this;
}

Span::~Span()
{
	_vec.clear();
	std::cout << RED"Destructor of Span Called"RESET << std::endl;
}

Span::Span(unsigned int N)
{
	_size = N;
	std::cout << RED"Constructor of Span Called"RESET << std::endl;
}

void Span::addNumber(int N)
{
	std::cout << "_vec.size = " << _vec.size() << "_size = " << _size << std::endl;
	if (_vec.size() >= _size)
		throw SpanFull();
	else
		_vec.push_back(N);
}

int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw NoNumber();
	int i = 2;
	std::sort(_vec.begin(), _vec.end());
	int minDiff = this->findpos(1) - this->findpos(0);
	//std::cout << "Min Diff = " << minDiff << " this->findpos(1) = " << this->findpos(1) << " this->findpos(0) "<< this->findpos(0) << std::endl;
	for (std::vector<int>::iterator it = _vec.begin() + 2; it < _vec.end(); it++)
	{
		//std::cout << " this->findpos(i) = " << this->findpos(i - 1) << " *it "<< *it << std::endl;
		minDiff = std::min(minDiff, *it - this->findpos(i - 1));
		i++;
	}
	//i = 2;
	// for (std::vector<int>::iterator it = _vec.begin() + 2; it < _vec.end(); it++)
	// {
	// 	if (*it - this->findpos(i - 1) == minDiff)
	// 	{
			return (std::abs(minDiff));
	// 	}
	// 	i++;
	// }
}

int Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw NoNumber();
	std::vector<int>::iterator biggest = _vec.begin();
	std::vector<int>::iterator shortest = _vec.begin();
	for (std::vector<int>::iterator in = _vec.begin(); in < _vec.end(); in++)
	{
		if (in > biggest)
			biggest = in;
		if (in < shortest)
			shortest = in;
	}
	//std::cout <<
	return (std::abs(*biggest - *shortest));
}

int Span::findpos(int pos) const
{
	// if (*_vec.begin() + pos > (int)_size)
	// 	throw NoOccurence();
	int i = 0;
	for (std::vector<int>::const_iterator it = _vec.begin(); it < _vec.end(); it++)
	{
		if (i == pos)
			return (*it);

		i++;
	}
	throw NoOccurence();
}

void Span::addMultiNumber(std::vector<int> toAdd)
{
	_vec.insert(_vec.end(), toAdd.begin(), toAdd.end());
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

