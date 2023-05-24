/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:19:49 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 10:03:32 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private :
		std::string _name;
	public :
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap& diamondtrap);
		DiamondTrap& operator= (const DiamondTrap& diamondtrap);
		~DiamondTrap(void);
		DiamondTrap(std::string name);
		using ScavTrap::attack;
		void whoAmI();
};

#endif
