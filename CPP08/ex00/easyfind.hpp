/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:50:01 by pjay              #+#    #+#             */
/*   Updated: 2023/06/18 16:10:34 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

class NoOccurence : public std::exception
{
	virtual const char* what() const throw()
	{
		return ("No occurence found");
	}
};

template <typename T>
typename T::iterator easyfind(T& temp, int a)
{

	for (typename T::iterator it = temp.begin(); it < temp.end(); it++)
	{
		if (*it == a)
			return (it);
	}
	throw NoOccurence();
}
