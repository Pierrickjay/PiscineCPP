/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:37:19 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 17:05:28 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "color.hpp"

class Animal
{
	protected :
		std::string _type;
	public :
		Animal(void);
		Animal(const Animal& animal);
		Animal& operator =(const Animal& animal);
		virtual ~Animal(void);
		std::string getType(void) const;
		virtual void makeSound(void) const;
};
