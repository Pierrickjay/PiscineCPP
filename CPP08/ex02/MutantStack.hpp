/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:48:59 by pjay              #+#    #+#             */
/*   Updated: 2023/07/10 15:25:14 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <deque>
#include "color.hpp"

// Function prototypes of MutantStack.tpp
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	MutantStack(void);
	MutantStack(const MutantStack& rhs);
	MutantStack& operator=(const MutantStack& rhs);
	~MutantStack(void);

	typedef typename std::deque<T>::iterator iterator;
	iterator begin(void);
	iterator end(void);
};

