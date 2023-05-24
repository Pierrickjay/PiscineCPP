/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:12:21 by pjay              #+#    #+#             */
/*   Updated: 2023/05/18 09:49:30 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
# include "color.hpp"
# include <fstream>

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const FragTrap& fragtrap);
		FragTrap& operator= (const FragTrap& fragtrap);
		~FragTrap(void);
		FragTrap(std::string name);
		void HighFivesGuys();
};

#endif
