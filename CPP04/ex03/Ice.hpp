/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:01:12 by pjay              #+#    #+#             */
/*   Updated: 2023/05/22 11:08:03 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
	public :
		Ice(void);
		Ice(const Ice& ice);
		Ice& operator =(const Ice& ice);
		~Ice(void);
		void use(ICharacter& target);
};
