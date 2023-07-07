/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:34:40 by pjay              #+#    #+#             */
/*   Updated: 2023/07/07 11:08:49 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe()
{

	#ifdef DEBUG
		std::cout << "Constructor of PmergeMe called" << std::endl;
	#endif
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& rhs)
{

	#ifdef DEBUG
		std::cout << "Constructor by assignement of PmergeMe called" << std::endl;
	#endif
}

template <typename T>
PmergeMe& PmergeMe<T>::operator=(const PmergeMe& rhs)
{

	#ifdef DEBUG
		std::cout << "Constructor by operator of PmergeMe called" << std::endl;
	#endif
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{

	#ifdef DEBUG
		std::cout << "Constructor of PmergeMe called" << std::endl;
	#endif
}

template <typename T>
void PmergeMe<T>::_SwapT(T& x, T& y)
{
	T a = y;

	y = x;
	x = a;
}

template <typename>
void PmergeMe<T>::_insertionSort(T& container)
{
	for (T::iterator it = container.begin(); it < container.end(); it++)
	{
		for(T::iterator itEnd = it ; itEnd != container.begin(); --itEnd)
		{
			if (*itEnd > *it)
				_SwapT(*itEnd, *it);
		}
	}
}

template <typename T>
void PmergeMe<T>::_mergeInsertionSort(T& lhs, T& rhs)
{
	if (lhs.size() < 16)
	{
		
	}
	//deiviser chaque cote
}


template <typename T>
PmergeMe<T>::PmergeMe(char **av)
{
	T lhs;
	T rhs;
	for (int i = 0; av[i]; i++)
	{
		if (i % 2 == 0)
		{
			rhs.push_back(atoi(av[i]));
		}
		else
		{
			lhs.push_back(atoi(av[i]));
		}
	}
}




