/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:04:43 by pjay              #+#    #+#             */
/*   Updated: 2023/07/10 16:18:45 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main()
{
	std::cout << RED"Main subject test" << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after the pop " << mstack.size() << std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << RED"---------------------" RESET << std::endl << std::endl << std::endl;
	std::cout << RED"My test" << RESET << std::endl;
	MutantStack<int> mstack2;
	mstack2.push(5);
	mstack2.push(17);
	std::cout << "mstack2 top is "<<mstack2.top() << std::endl;
	MutantStack<int>copy(mstack2);
	std::cout << "copy top is "<< copy.top() << std::endl;
	std::cout << "Size before the pop " << copy.size() << std::endl;
	copy.pop();
	std::cout << "Size after the pop " << copy.size() << std::endl;
	mstack2 = copy;
	std::cout << "Mstack top after using operator = on copy"<<mstack2.top() << std::endl;
}
