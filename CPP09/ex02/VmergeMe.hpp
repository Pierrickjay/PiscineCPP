/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:45:15 by pjay              #+#    #+#             */
/*   Updated: 2023/08/07 15:29:08 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include "Number.hpp"


class VmergeMe
{
	private :
		// Cannonical form
		VmergeMe();
		VmergeMe(const VmergeMe& rhs);
		VmergeMe& operator=(const VmergeMe& rhs);
		// end

		std::vector<Number> _pend;
		std::vector<Number> _S;
		size_t	_size;

		void arrangePair(std::vector<std::pair<int, int> >& arr);
		void arrangeArray(std::vector<std::pair<int, int> >& arr);
		void printArr(std::vector<std::pair<int, int> >& arr);
		void printArr(std::vector<Number>& arr);
		void printArr(std::vector<int>& arr);
		void sortBigArray(std::vector<Number> &arr);
		int binarySearch(std::vector<Number> arr, int item, int low, int high);
		void sortFinalArray();

		void arrangeBig(std::vector<Number>::iterator insertPos);
		Number& findTheNumb(unsigned int index, std::vector<Number> arr);
	public :
		VmergeMe(std::vector<std::pair<int, int> >& arr);
		~VmergeMe();
};
//24
