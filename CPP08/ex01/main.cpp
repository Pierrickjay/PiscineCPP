/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:06:41 by pjay              #+#    #+#             */
/*   Updated: 2023/06/23 16:28:30 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main_func()
{
	std::cout << BLUE "---------MAIN OF THE SUBJECT---------" RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortest Span = "<< sp.shortestSpan() << std::endl;
	std::cout << "longest Span =" << sp.longestSpan() << std::endl;
	std::cout << BLUE "----END OF MAIN OF THE SUBJECT------" RESET << std::endl << std::endl<< std::endl;
	return 0;
}


int main()
{
	main_func();
	std::cout << BLUE "----PERSONNAL MAIN------" RESET << std::endl;
	Span sp = Span(10);
	std::vector<int> po;
	int arr[] = {91, 15, 1665, 22, 12151, 1918, 91489, 9884, 9849};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	po.insert(po.begin(), arr, arr + size);
	srand(time(NULL));
	try
	{
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(5);
		std::cout <<MAGENTA "------------"RESET <<std::endl;
		std::cout << "shortest Span = "<< sp.shortestSpan() << std::endl;
		std::cout << "longest Span = " << sp.longestSpan() << std::endl;
		std::cout <<MAGENTA "------------"RESET <<std::endl;
		sp.addMultiNumber(po);
		sp.printSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout <<BLUE "-----------------------------------------"RESET <<std::endl;
	try
	{
		Span toFail = Span(5);
		std::cout << "Shortest Span = " <<toFail.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout <<BLUE "-----------------------------------------"RESET <<std::endl;
	try
	{
		Span toFail(5);
		std::cout << "Shortest Span = "<< toFail.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout <<BLUE "----Add multi number with an array of int----"RESET <<std::endl;
	try
	{
		Span toFail = Span(10000);
		toFail.addMultiNumber(po);
		std::cout << "Shortest Span = "<< toFail.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Shortest Span = "<< e.what() << '\n';
	}
	std::cout <<BLUE "----Add multi number with begin and end iterator----"RESET <<std::endl;
	try
	{
		Span toFail = Span(10000);
		toFail.addMultiNumber(po.begin(), po.end());
		std::cout << "Shortest Span = "<< toFail.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout <<BLUE "---------Creating the big Span---------"RESET <<std::endl;
	try
	{
		Span BigOne(100000);
		for (int i = 0; i < 100000; i++)
		{
			BigOne.addNumber(rand() % 100000);
		}
		std::cout << "Succeed to add 100 000 number to the span" << std::endl;
		std::cout << "Shortest Span of bigOne is " << BigOne.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
