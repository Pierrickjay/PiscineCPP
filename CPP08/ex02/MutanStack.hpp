/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:48:59 by pjay              #+#    #+#             */
/*   Updated: 2023/06/20 15:34:21 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include "color.hpp"
template <typename T>
class MutantStack : public std::stack<T> {
	public:
	MutantStack(void) : std::stack<T>() {}; // calling the constructor of stack to initialize

	typedef typename std::deque<T>::iterator iterator; // typename cause he is dependant of the T

	iterator begin(void) {
		return (this->c.begin());
	}

	iterator end(void) {
		return (this->c.end());
	}
};
