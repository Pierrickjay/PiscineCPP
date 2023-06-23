/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:26:44 by pjay              #+#    #+#             */
/*   Updated: 2023/06/18 14:46:53 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	std::cout << BLUE"Constructor of Array called" RESET<< std::endl;
	_array = new T[0]();
	_size = 0;
}

template <typename T>
Array<T>::Array(const Array& rhs)
{
	std::cout << BLUE"Constructor by copy of Array called" RESET<< std::endl;
	this->_array = new T[rhs.size()];
	for (unsigned int i = 0; i < rhs.size(); i++)
		this->_array[i] = rhs._array[i];
	_size = rhs.size();
}

template <typename T>
const Array<T>& Array<T>::operator= (const Array& rhs)
{
		std::cout << BLUE"Constructor by assignement operator called" RESET<< std::endl;
		if (this != &rhs)
		{
			delete _array;
			this->_array = new T[rhs.size()];
			for (unsigned int i = 0; i < rhs.size(); i++)
				this->_array[i] = rhs._array[i];
			_size = rhs.size();
		}
}

template <typename T>
const char* Array<T>::IndexOut::what() const throw(){
	return ("Index Out of Bounds");
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw IndexOut();
	else
	{
		return (_array[index]);
	}
}

template <typename T>
Array<T>::~Array()
{
	if (_array)
		delete [] _array;
	std::cout << BLUE"Destructor of Array called" RESET<< std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << BLUE"Constructor of Array called" RESET<< std::endl;
	_array = new T[n]();
	_size = n;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

