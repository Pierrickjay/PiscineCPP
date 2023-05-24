/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:38:24 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 16:08:23 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
	public :
		Cat(void);
		Cat(const Cat& Cat);
		Cat& operator =(const Cat& Cat);
		~Cat(void);
		void makeSound(void) const;
};
