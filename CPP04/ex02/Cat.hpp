/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:38:24 by pjay              #+#    #+#             */
/*   Updated: 2023/05/25 11:04:24 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
	private :
		Brain *_brain;
	public :
		Cat(void);
		Cat(const Cat& Cat);
		Cat& operator =(const Cat& Cat);
		~Cat(void);
		Brain* getBrain(void);
		void makeSound(void) const;
};
