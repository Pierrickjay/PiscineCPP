/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:07:35 by pjay              #+#    #+#             */
/*   Updated: 2023/03/31 16:09:20 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H
# include <iostream>

using std::string;

class Weapon
{
	private:
		string _type;

	public:
		const string &getType(void);
		void setType(string toChange);
		Weapon(string gun);
		~Weapon(void);
};

#endif
