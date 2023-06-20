/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:46:55 by pjay              #+#    #+#             */
/*   Updated: 2023/05/29 09:23:28 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Brain
{
	private :
		std::string _ideas[100];
	public :
		Brain(void);
		Brain(const Brain& cerveau);
		Brain& operator =(const Brain& cerveau);
		~Brain(void);
		void setArrayNumber(std::string ideas, int N);
		std::string getArrayNumber(int N);
};
