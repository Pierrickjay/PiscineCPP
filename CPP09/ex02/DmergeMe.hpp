/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:19:33 by pjay              #+#    #+#             */
/*   Updated: 2023/08/07 15:42:18 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include "Number.hpp"

class DmergeMe
{
	private :
		// Cannonical form
		DmergeMe();
		DmergeMe(const DmergeMe& rhs);
		DmergeMe& operator=(const DmergeMe& rhs);
		// end

		std::deque<Number> _pend;
		std::deque<Number> _S;
		size_t	_size;

		void arrangePair(std::deque<std::pair<int, int> >& arr);
		void arrangeArray(std::deque<std::pair<int, int> >& arr);
		void printArr(std::deque<Number>& arr);
		void sortBigArray(std::deque<Number> &arr);
		void sortFinalArray();

		void arrangeBig(std::deque<Number>::iterator insertPos);
		Number& findTheNumb(unsigned int index, std::deque<Number> arr);
	public :
		DmergeMe(std::deque<std::pair<int, int> >& arr);
		~DmergeMe();
};
