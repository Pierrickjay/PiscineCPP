/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:27:33 by pjay              #+#    #+#             */
/*   Updated: 2023/03/31 15:59:27 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *_gun;
		string _name;
	public:
		void attack(void);
		void setWeapon(Weapon &gun);
		HumanB(string name);
		~HumanB(void);
};
#endif
