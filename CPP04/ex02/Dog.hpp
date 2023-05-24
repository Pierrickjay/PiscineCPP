/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:38:24 by pjay              #+#    #+#             */
/*   Updated: 2023/05/19 09:14:18 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	private :
		Brain *_brain;
	public :
		Dog(void);
		Dog(const Dog& Dog);
		Dog& operator =(const Dog& Dog);
		~Dog(void);
		Brain* getBrain(void);
		void makeSound(void) const;
};
