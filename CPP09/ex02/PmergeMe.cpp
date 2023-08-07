/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:34:40 by pjay              #+#    #+#             */
/*   Updated: 2023/08/07 16:39:03 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	#ifdef DEBUG
		std::cout << "Constructor of PmergeMe called" << std::endl;
	#endif
}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	(void)rhs;
	#ifdef DEBUG
		std::cout << "Constructor by assignement of PmergeMe called" << std::endl;
	#endif
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	#ifdef DEBUG
		std::cout << "Constructor by operator of PmergeMe called" << std::endl;
	#endif
	(void)rhs;
	return (*this);
}

PmergeMe::~PmergeMe()
{

	#ifdef DEBUG
		std::cout << "Constructor of PmergeMe called" << std::endl;
	#endif
}

void printNonSorted(char **av)
{
	std::cout << "Before : ";
	for (int i = 1; av[i]; i++)
		std::cout << av[i] << " ";
	std::cout << std::endl;
}

int dealWithVec(char **av, int ac)
{
	std::vector<std::pair<int, int> > arr;
	int i = 1;
	printNonSorted(av);
	clock_t begin = clock();
	while (av[i])
	{
		int tmp2 = -1;
		int tmp = atoi(av[i]);
		if (av[i + 1])
			tmp2 = atoi(av[i + 1]);
		if (tmp < 0)
		{
			BAD_PARAM
			return (-1);
		}
		arr.push_back(std::make_pair(tmp, tmp2));
		if (i + 2 > ac)
			break ;
		i += 2;
	}
	VmergeMe te(arr);
	clock_t end = clock();
	double timePassed = static_cast<double>(end - begin) / CLOCKS_PER_SEC * 10;
	std::cout << "Time to process a range of " << ac << " with " << "std::vector : " << timePassed << " us" << std::endl;
	return (0);
}

int dealWithDeq(char **av, int ac)
{
	std::deque<std::pair<int, int> > arr;
	int i = 1;
	clock_t begin = clock();
	while (av[i])
	{
		int tmp2 = -1;
		int tmp = atoi(av[i]);
		if (av[i + 1])
			tmp2 = atoi(av[i + 1]);
		if (tmp < 0)
		{
			BAD_PARAM
			return (-1);
		}
		arr.push_back(std::make_pair(tmp, tmp2));
		if (i + 2 > ac)
			break ;
		i += 2;
	}
	DmergeMe te(arr);
	clock_t end = clock();
	double timePassed = static_cast<double>(end - begin) / CLOCKS_PER_SEC  * 10;
	std::cout << "Time to process a range of " << ac << " with " << "std::deque : " << timePassed << " us" << std::endl;
	return (0);

}

PmergeMe::PmergeMe(char **av, int ac)
{
	(void)ac;

	dealWithVec(av, ac);
	dealWithDeq(av, ac);
}
