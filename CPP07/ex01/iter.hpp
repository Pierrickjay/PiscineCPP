/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:28:45 by pjay              #+#    #+#             */
/*   Updated: 2023/07/11 14:28:03 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void printIt(T &element)
{
	std::cout << element << " ";
}

template <typename T, typename Func>
void iter(T* array, int length, Func func)
{
	if (!array)
	{
		std::cout << " NULL PTR"<< std::endl;
		return ;
	}
	for (int i = 0; i < length; i++)
	{
		func(array[i]);
	}
}
