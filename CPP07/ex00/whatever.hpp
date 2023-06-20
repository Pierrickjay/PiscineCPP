/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:03:47 by pjay              #+#    #+#             */
/*   Updated: 2023/06/17 14:27:00 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
// au moment de la compilation le compileur regarde le type de donne
// que nous comparons et va copier nos teplate avec le type de donne necessaire

template <typename T> T max(T x, T y)
{
	return (x > y ? x : y);
}

template <typename T> T min(T x, T y)
{
	return (x < y ? x : y);
}

template <typename T> void swap(T& x, T& y)
{
	T a = y;

	y = x;
	x = a;
}
