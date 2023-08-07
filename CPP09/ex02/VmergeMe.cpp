/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:47:15 by pjay              #+#    #+#             */
/*   Updated: 2023/08/07 16:40:26 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "VmergeMe.hpp"

VmergeMe::VmergeMe()
{
	#ifdef DEBUG
		std::cout << "Constructor of VmergeMe called" << std::endl;
	#endif
}


VmergeMe::VmergeMe(const VmergeMe& rhs)
{
	*this = rhs;
	#ifdef DEBUG
		std::cout << "Constructor by assignement of VmergeMe called" << std::endl;
	#endif
}


VmergeMe& VmergeMe::operator=(const VmergeMe& rhs)
{
	#ifdef DEBUG
		std::cout << "Constructor by operator of VmergeMe called" << std::endl;
	#endif
	if (this != &rhs)
	{
		_S = rhs._S;
		_pend = rhs._pend;
		_size = rhs._size;
	}
	return (*this);
}


VmergeMe::~VmergeMe()
{

	#ifdef DEBUG
		std::cout << "Constructor of VmergeMe called" << std::endl;
	#endif
}


void VmergeMe::printArr(std::vector<Number>& arr)
{
	for (size_t i = 0 ; i < arr.size() ; i++)
	{
		std::cout << arr[i].getNumb() << " ";
	}
	std::cout << std::endl;
}

void VmergeMe::sortBigArray(std::vector<Number>& arr)
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

void VmergeMe::arrangePair(std::vector<std::pair<int, int> >& arr)
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

void VmergeMe::arrangeArray(std::vector<std::pair<int, int> >& arr)
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

Number& VmergeMe::findTheNumb(unsigned int index, std::vector<Number> arr)
{
	std::vector<Number>::iterator it = arr.begin();
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

std::vector<Number>::iterator checkFoundpos(std::vector<Number>::iterator found, std::vector<Number>& arr, int a)
{
	std::vector<Number>::iterator goodPlace = found;

	for (std::vector<Number>::iterator it = found; ; it--)
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


std::vector<Number>::iterator getPos(unsigned int index, std::vector<Number>& arr, int a) {
	std::vector<Number>::iterator it = arr.begin();
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

void VmergeMe::sortFinalArray()
{
	unsigned long arr[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531};
	std::vector<unsigned long> jacobSeq;
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
			std::vector<Number>::iterator it = getPos(tmp.getIndPair(), _S, tmp.getNumb());
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
VmergeMe::VmergeMe(std::vector<std::pair<int, int> >& arr)
{
	arrangePair(arr);
	arrangeArray(arr);
	sortFinalArray();
	std::cout << "After : ";
	printArr(_S);
}
