/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:47:26 by pjay              #+#    #+#             */
/*   Updated: 2023/06/15 14:16:20 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serialize
{
	public :
		Serialize();
		Serialize(const Serialize& rhs);
		Serialize& operator= (const Serialize& rhs);
		~Serialize();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		class ConversionImpossible : public std::exception
		{
			public:
  				virtual const char* what() const throw();
		};
		
};
