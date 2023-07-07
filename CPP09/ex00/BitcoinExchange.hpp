/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:56:37 by pjay              #+#    #+#             */
/*   Updated: 2023/07/05 12:40:04 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "color.hpp"
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <map>

class BitcoinExchange
{
	private :
		std::map<std::string, std::string> _toStock;
		std::map<std::string, float> _btcValue;
	public :
		BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange &rhs);
		BitcoinExchange(const BitcoinExchange &rhs);
		~BitcoinExchange();
		void	ExchangeIt(char *av);
		int		checkIt(std::string save);
		void	printSwap();
		void	fillMap(std::ifstream &btcValue);
};

