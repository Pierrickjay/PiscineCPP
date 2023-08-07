/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:14:30 by pjay              #+#    #+#             */
/*   Updated: 2023/08/07 15:46:43 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DmergeMe.hpp"

DmergeMe::DmergeMe()
{
	#ifdef DEBUG
		std::cout << "Constructor of DmergeMe called" << std::endl;
	#endif
}


DmergeMe::DmergeMe(const DmergeMe& rhs)
{
	*this = rhs;
	#ifdef DEBUG
		std::cout << "Constructor by assignement of DmergeMe called" << std::endl;
	#endif
}


DmergeMe& DmergeMe::operator=(const DmergeMe& rhs)
{
	#ifdef DEBUG
		std::cout << "Constructor by operator of DmergeMe called" << std::endl;
	#endif
	if (this != &rhs)
	{
		_S = rhs._S;
		_pend = rhs._pend;
		_size = rhs._size;
	}
	return (*this);
}


DmergeMe::~DmergeMe()
{

	#ifdef DEBUG
		std::cout << "Constructor of DmergeMe called" << std::endl;
	#endif
}

void DmergeMe::printArr(std::deque<Number>& arr)
{
	for (size_t i = 0 ; i < arr.size() ; i++)
	{
		std::cout << arr[i].getNumb() << " ";
	}
}

void DmergeMe::sortBigArray(std::deque<Number>& arr)
{
	for (size_t i = 0 ; i < arr.size() ; i++)
	{
		for (size_t j = 0 ; j < arr.size() - 1 ; j++)
		{
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
	}
}

void DmergeMe::arrangePair(std::deque<std::pair<int, int> >& arr)
{
	for (size_t i = 0 ; i < arr.size() ; i++)
	{
		if (arr[i].first < arr[i].second)
		{
			int tmp = arr[i].first;
			arr[i].first = arr[i].second;
			arr[i].second = tmp;
		}
	}
}


void DmergeMe::arrangeArray(std::deque<std::pair<int, int> >& arr)
{
	for (size_t i = 0 ; i < arr.size() ; i++)
	{
		int tmpR = arr[i].first;
		int tmpL = arr[i].second;
		if (tmpL == -1)
		{
			_S.push_back(Number(tmpR, i));
			sortBigArray(_S);
			continue;
		}
		_S.push_back(Number(tmpR, i));
		sortBigArray(_S);
		_pend.push_back(Number(tmpL, i));
	}

}


Number& DmergeMe::findTheNumb(unsigned int index, std::deque<Number> arr)
{
	std::deque<Number>::iterator it = arr.begin();
	unsigned int i = 0;
	while(it != arr.end())
	{
		if (i == index)
			return (*it);
		it++;
		i++;
	}
	return (*it);
}

std::deque<Number>::iterator checkFoundpos(std::deque<Number>::iterator found, std::deque<Number>& arr, int a)
{
	std::deque<Number>::iterator goodPlace = found;

	for (std::deque<Number>::iterator it = found; ; it--)
	{

		if (it->getNumb() > a)
		{
			goodPlace = it;
		}
		if (it == arr.begin())
			break;
	}
	return (goodPlace);
}


std::deque<Number>::iterator getPos(unsigned int index, std::deque<Number>& arr, int a) {
	std::deque<Number>::iterator it = arr.begin();
	while (it != arr.end())
	{
		if (it->getIndPair() == index)
		{
			return (checkFoundpos(it, arr, a));
		}
		it++;
	}
	return (arr.end());
}

void DmergeMe::sortFinalArray()
{
	unsigned long arr[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531};
	std::deque<unsigned long> jacobSeq;
	jacobSeq.assign(arr, arr + sizeof(arr) / sizeof(arr[0]));

	_size = _S.size() + _pend.size();
	size_t add = 0;
	while (_S.size() != _size)
	{
		unsigned int oldJacobNumber = jacobSeq[0];
		jacobSeq.erase(jacobSeq.begin());
		unsigned int a = 0;
		for (unsigned int i = jacobSeq[0] - 1; i >= oldJacobNumber; i--)
		{
			if (add >= _pend.size())
			{
				return ;
			}
			while (i - a > _pend.size())
				a++;
			Number tmp = findTheNumb(i - a - 1, _pend);
			std::deque<Number>::iterator it = getPos(tmp.getIndPair(), _S, tmp.getNumb());
			_S.insert(it, tmp);
			add++;
		}
		if (add >= _pend.size())
		{
			break;
		}
		if (_pend.size() == 0)
				break;
	}
}
DmergeMe::DmergeMe(std::deque<std::pair<int, int> >& arr)
{
	arrangePair(arr);
	arrangeArray(arr);
	sortFinalArray();
	// std::cout << "After : ";
	// printArr(_S);
}
