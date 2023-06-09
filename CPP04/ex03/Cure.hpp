/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:02:24 by pjay              #+#    #+#             */
/*   Updated: 2023/05/24 10:36:08 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
	public :
		Cure(void);
		Cure(const Cure& cure);
		Cure& operator =(const Cure& cure);
		~Cure(void);
		void use(ICharacter& target);
		AMateria* clone() const;
};
