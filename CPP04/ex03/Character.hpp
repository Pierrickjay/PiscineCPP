/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:42:10 by pjay              #+#    #+#             */
/*   Updated: 2023/05/22 13:35:37 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Character : ICharacter
{
	private :
		std::string _MatName[4];
	public:
		Character(void);
		Character(const Character& character);
		Character& operator =(const Character& character);
		~Character(void);

};
