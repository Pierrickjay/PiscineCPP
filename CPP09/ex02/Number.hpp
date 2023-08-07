/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:23:53 by pjay              #+#    #+#             */
/*   Updated: 2023/08/05 10:27:05 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Number
{
	private :
		int _n;
		unsigned int _indPair;
	public :
		//void setIndPair(unsigned int indPair);
		// Cannonical form
		Number();
		Number(const Number& rhs);
		Number& operator=(const Number& rhs);
		~Number();
		// end
		unsigned int getIndPair() const;
		int getNumb() const;
		Number(int n, unsigned int indPair);
		bool operator<(const Number& rhs) const;
		bool operator>(const Number& rhs) const;
};
