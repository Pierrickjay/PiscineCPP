/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:50:02 by pjay              #+#    #+#             */
/*   Updated: 2023/04/15 16:47:52 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <map>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	error(void);
		void	warning(void);
	public:
		void	complain(std::string level);
};

#endif
