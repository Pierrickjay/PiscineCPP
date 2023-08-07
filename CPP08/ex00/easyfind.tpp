/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:50:01 by pjay              #+#    #+#             */
/*   Updated: 2023/07/10 14:35:51 by pjay             ###   ########.fr       */
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

	if (std::find(temp.begin(), temp.end(), a) != temp.end())
		return (std::find(temp.begin(), temp.end(), a));
	else
		throw NoOccurence();
}
