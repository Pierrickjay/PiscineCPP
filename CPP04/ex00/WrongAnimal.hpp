/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:45:08 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 16:46:50 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class WrongAnimal
{
	protected :
		std::string _type;
	public :
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& wronganimal);
		WrongAnimal& operator =(const WrongAnimal& wronganimal);
		~WrongAnimal(void);
		std::string getType(void) const;
		void makeSound(void) const;
};
