/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:21:30 by pjay              #+#    #+#             */
/*   Updated: 2023/07/10 14:46:04 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include "easyfind.hpp"
#include "color.hpp"


class Span
{
	private :
		std::vector<int> _vec;
		unsigned int _size;
	public:
		Span();
		Span(const Span& rhs);
		Span& operator=(const Span& rhs);
		~Span();

		Span(unsigned int N);
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();Of course, you will write your own tests and they will be way more thorough than the
ones below. Test your Spa
		void addMultiNumber(std::vector<int> toAdd);
		void addMultiNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void printSpan();
		class SpanFull : public std::exception
		{
			virtual const char* what() const throw();
		};
		class NoNumber : public std::exception
		{
			virtual const char* what() const throw();
		};
};

