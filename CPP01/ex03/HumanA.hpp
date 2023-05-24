/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:26:23 by pjay              #+#    #+#             */
/*   Updated: 2023/03/31 13:45:28 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAMNA_HPP
# define HUMAMNA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		Weapon &_gun;
		string _name;
	public:
		void attack(void);
		HumanA(string name, Weapon& gun);
		~HumanA(void);
};
# endif
