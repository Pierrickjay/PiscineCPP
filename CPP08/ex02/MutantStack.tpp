/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:47:29 by pjay              #+#    #+#             */
/*   Updated: 2023/07/10 16:18:02 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MutantStack.hpp"

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (typename MutantStack<T>::iterator(std::stack<T>::c.begin()));
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (typename MutantStack<T>::iterator(std::stack<T>::c.end()));
}

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
	#ifdef DEBUG
		std::cout << BLUE"MutantStack constructor called" << RESET << std::endl;
	#endif
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& rhs) : std::stack<T>(rhs)
{
	#ifdef DEBUG
		std::cout << BLUE"MutantStack constructor by assignement called" << RESET << std::endl;
	#endif
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& rhs)
{
	if (this != &rhs)
	{
		std::stack<T>::operator=(rhs);
	}
	#ifdef DEBUG
		std::cout << BLUE"MutantStack operator called" << RESET << std::endl;
	#endif
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	#ifdef DEBUG
		std::cout << BLUE"MutantStack destructor called" << RESET << std::endl;
	#endif
}
