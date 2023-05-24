/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:50:02 by pjay              #+#    #+#             */
/*   Updated: 2023/04/17 17:25:48 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <map>
#define PRINT std::cout<<__LINE__<<" " << __FILE__ << std::cout;

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
