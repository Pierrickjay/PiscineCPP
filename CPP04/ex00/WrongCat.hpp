/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:48:23 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 16:49:27 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"


class WrongCat : public WrongAnimal
{
	public :
		WrongCat(void);
		WrongCat(const WrongCat& wrongcat);
		WrongCat& operator =(const WrongCat& wrongcat);
		~WrongCat(void);
		void makeSound(void) const;
};
