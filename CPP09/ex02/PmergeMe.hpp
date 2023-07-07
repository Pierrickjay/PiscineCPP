/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:35:02 by pjay              #+#    #+#             */
/*   Updated: 2023/07/07 11:00:02 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <ctime>
#include <utility>

#define BAD_PARAM std::cout << "Please enter as parametters a list of positive integer" << std::endl;

template <typename T>
class PmergeMe
{
	private :
		// Cannonical form
		PmergeMe();
		PmergeMe(const PmergeMe& rhs);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();
		// end

		T sortArray;
		void _insertionSort(T& container);
		void _mergeInsertionSort(T& lhs, T& rhs);
		void _SwapT(T& x, T& y);
	public :
		PmergeMe(char **av);
};
