/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:28:45 by pjay              #+#    #+#             */
/*   Updated: 2023/06/21 12:58:46 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void printIt(const T &element)
{
	std::cout << element << " ";
}

template <typename T, typename Func>
void iter(T* array, int length, Func func)
{
	for (int i = 0; i < length; i++)
	{
		func(array[i]);
	}
}
