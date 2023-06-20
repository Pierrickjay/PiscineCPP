/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:06:41 by pjay              #+#    #+#             */
/*   Updated: 2023/06/20 12:26:27 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main()
{
	Span sp = Span(200);
	std::vector<int> po;
	int arr[] = {91, 15, 1665, 22, 12151, 1918, 91489, 9884, 9849};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	po.insert(po.begin(), arr, arr + size);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(6);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addMultiNumber(po);
		sp.printSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
