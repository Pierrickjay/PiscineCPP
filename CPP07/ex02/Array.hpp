/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:13:50 by pjay              #+#    #+#             */
/*   Updated: 2023/06/18 14:36:26 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "color.hpp"
#include <stdint.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

template<typename T>
class Array
{
	private :
		T *_array;
		unsigned int _size;
	public :
		Array();
		Array(const Array& rhs);
		const Array& operator= (const Array& rhs);
		~Array();

		T& operator[](unsigned int index);
		Array(unsigned int n);
		unsigned int size() const;
		class IndexOut : public std::exception
		{
			public:
  				virtual const char* what() const throw();
		};
};

