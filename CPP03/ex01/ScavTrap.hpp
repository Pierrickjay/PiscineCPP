/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:56:19 by pjay              #+#    #+#             */
/*   Updated: 2023/05/15 11:59:09 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include "color.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap& scavtrap);
		ScavTrap& operator= (const ScavTrap& scavtrap);
		~ScavTrap(void);
		ScavTrap(std::string name);
		void guardGate();
		void attack(const std::string& target);
};
#endif
