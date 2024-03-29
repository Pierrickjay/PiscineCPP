/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:35:02 by pjay              #+#    #+#             */
/*   Updated: 2023/08/07 15:36:58 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <stdlib.h>
#include <ctime>
#include "VmergeMe.hpp"
#include "DmergeMe.hpp"

#define BAD_PARAM std::cout << "Please enter as parametters a list of positive integer" << std::endl;


class PmergeMe
{
	private :
		// Cannonical form
		PmergeMe();
		PmergeMe(const PmergeMe& rhs);
		PmergeMe& operator=(const PmergeMe& rhs);
		// end

	public :
		PmergeMe(char **av, int ac);
		~PmergeMe();
};

void printNonSorted(char **av);
