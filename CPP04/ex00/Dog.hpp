/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:38:24 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 16:08:29 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog(void);
		Dog(const Dog& Dog);
		Dog& operator =(const Dog& Dog);
		~Dog(void);
		void makeSound(void) const;
};
