/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:21:30 by pjay              #+#    #+#             */
/*   Updated: 2023/06/20 12:20:34 by pjay             ###   ########.fr       */
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
		int longestSpan();
		int findpos(int pos) const;
		void addMultiNumber(std::vector<int> toAdd);
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
