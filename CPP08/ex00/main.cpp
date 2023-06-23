/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:09:21 by pjay              #+#    #+#             */
/*   Updated: 2023/06/23 11:13:28 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> a1 (4, 100);
	a1.push_back(88);
	a1.push_back(10);
	a1.push_back(14);
	a1.push_back(200);
	a1.push_back(489);
	for (std::vector<int>::iterator it = a1.begin(); it < a1.end(); it++)
		std::cout << *it << " | ";
	std::cout << std::endl;
	try
	{
		std::vector<int>::iterator result = easyfind(a1, 88);
		std::cout << *result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::vector<int>::iterator result = easyfind(a1, 489);
		std::cout << *result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::vector<int>::iterator result = easyfind(a1, 25);
		std::cout << *result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
