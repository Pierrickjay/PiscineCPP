/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:28:45 by pjay              #+#    #+#             */
/*   Updated: 2023/06/17 15:02:50 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

//si on l'apelle avec un char * cela va deplacer le pointeur de 1 vers la droite
// ce qui entrainera la perte du premier caractere.
template <typename T>
void printIt(T &element){
	std::cout << element << " ";
	element++;
	std::cout << element << " | ";
}

template <typename T, typename Func>
void iter(T* array, int length, Func func)
{
	for (int i = 0; i < length; i++)
	{
		func(array[i]);
	}
	std::cout << std::endl;
	for (int i = 0; i < length; i++)
	{
		func(array[i]);
	}
}
