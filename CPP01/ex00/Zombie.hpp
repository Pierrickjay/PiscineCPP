/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:45:39 by pjay              #+#    #+#             */
/*   Updated: 2023/04/18 14:10:35 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

using std::string;


class Zombie
{
	private:
		string _name;
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void setName(std::string name);
		void announce(void);
};
void randomChump(std::string name);
Zombie *newZombie(std::string name);
#endif
