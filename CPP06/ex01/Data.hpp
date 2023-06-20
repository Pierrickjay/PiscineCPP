/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:57:15 by pjay              #+#    #+#             */
/*   Updated: 2023/06/15 14:50:02 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "color.hpp"
#include <iostream>

class Data
{
	private :
		std::string _name;
	public :
		Data();
		Data(const Data& rhs);
		Data& operator= (const Data& rhs);
		~Data();
		Data(std::string Name);
		std::string getName();
};

