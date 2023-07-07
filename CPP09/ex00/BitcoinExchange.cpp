/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:56:06 by pjay              #+#    #+#             */
/*   Updated: 2023/07/06 14:47:32 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
	#ifdef DEBUG
		std::cout << RED"Constructor by default of BtcExchg called" RESET << std::endl;
	#endif
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	(void)rhs;
	#ifdef DEBUG
		std::cout << RED"Constructor by operator of BtcExchg called" RESET << std::endl;
	#endif
	return (*this);
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
	(void)rhs;
	#ifdef DEBUG
		std::cout << RED"Constructor by assignement of BtcExchg called" RESET << std::endl;
	#endif
}
BitcoinExchange::~BitcoinExchange()
{
	#ifdef DEBUG
		std::cout << RED"Destrcutor of BtcExchg called" RESET << std::endl;
	#endif
}

void BitcoinExchange::ExchangeIt(char *av)
{
	std::ifstream ExcRate;
	std::ifstream toBuy;
	std::string save;

	try
	{
		ExcRate.open("data.csv");
		toBuy.open(av);
		fillMap(ExcRate);
		while (std::getline(toBuy, save))
		{
			if (checkIt(save) == -1)
				continue ;
			else
			{
				printSwap();
				_toStock.clear();
			}
			//std::cout << " All good the the line => " << save << std::endl;
		}
	}
	catch(std::ios_base::failure& e)
	{

		std::cout << "Te" << std::endl;
		ExcRate.close(); // if to buy failed
		std::cerr << e.what() << '\n';
	}

}

void print_map(std::map<std::string, float> mapp)
{
	std::map<std::string, float>::iterator it;
	for (it = mapp.begin(); it != mapp.end(); it++)
	{
		std::cout << "First = " << it->first << " | Second = " << it->second << std::endl;
	}
}


void	BitcoinExchange::fillMap(std::ifstream &btcfd)
{
	std::string line;
	int i = 0;
	while(getline(btcfd, line))
	{
		if (i != 0)
		{
			int findbreak = line.find(',');
			_btcValue[line.substr(0, findbreak)] = atof(line.substr(findbreak + 1, line.length() - findbreak).c_str());
		}
		i++;
	}
}

//compare each date element between them AAAA then MM then DD
std::string findClosestDate(std::map<std::string, std::string> toEx, std::map<std::string, float> btcValue)
{
	std::map<std::string, std::string>::iterator itToEx = toEx.begin();
	std::string tmp;
	std::string closeDate;
	for (std::map<std::string, float>::iterator it = btcValue.begin(); it != btcValue.end(); it++)
	{
		int numToEx = atoi(itToEx->first.substr(0, 4).c_str());
		int numBtc = atoi(it->first.substr(0, 4).c_str());
		if (it == btcValue.begin() && numToEx < numBtc)
		{
			std::cout << "out here" << std::endl;
			return (it->first);
		}
		if (numBtc <= numToEx )
		{
			//std::cout << "numbtc = " << numBtc << " || num ex" << numToEx << std::endl;
			closeDate = it->first.substr(0, 4);

		}
	}
	//std::cout<< "date find first part " << closeDate << std::endl;
	for (std::map<std::string, float>::iterator it = btcValue.begin(); it != btcValue.end(); it++)
	{
		int numToEx = atoi(itToEx->first.substr(5, 2).c_str());
		//std::cout << it->first << std::endl;
		int numBtc = atoi(it->first.substr(5, 2).c_str());

		if (closeDate == it->first.substr(0, 4))
		{
			//std::cout << "num btc" << numBtc << " of " << it->first.substr(6, 2).c_str() << "   | num to ex = " << numToEx << std::endl;
			if (numBtc <= numToEx )
			{
				tmp = it->first.substr(4, 4);
				//std::cout << tmp << std::endl;
			}
		}
	}
	closeDate += tmp;
	//std::cout<< "date find second part " << closeDate << std::endl;
	for (std::map<std::string, float>::iterator it = btcValue.begin(); it != btcValue.end(); it++)
	{
		int numToEx = atoi(itToEx->first.substr(8, 2).c_str());
		int numBtc = atoi(it->first.substr(8, 2).c_str());
		if (closeDate == it->first.substr(0, 8))
		{
			//std::cout << " it->first.substr(0, 8) = " <<  it->first.substr(0, 8) << " numBtc " << numBtc << " numToEx " << numToEx<< std::endl;
			if (numBtc <= numToEx)
				tmp = it->first.substr(8, 2);
		}
	}
	closeDate += tmp;
	//std::cout << "close date = " << closeDate << " of " << itToEx->first << std::endl;
	return (closeDate);
}

void	 BitcoinExchange::printSwap()
{
	std::map<std::string, float>::iterator itBtc;
	std::map<std::string, std::string>::iterator it =_toStock.begin();
	std::string tmpString = findClosestDate(_toStock, _btcValue);
	long int toMultInt = 0;
	float toMultFloat = 0;
	std::cout << it->first << " => " << it->second << " = ";
	size_t posVirg = it->second.find('.');
	for (itBtc = _btcValue.begin(); itBtc->first != tmpString && itBtc != _btcValue.end(); itBtc++){
		;
	}
	if (itBtc != _btcValue.end())
	{
		if (posVirg == std::string::npos)
		{
			//std::cout << it->second.length() << std::endl;
			toMultInt = atoi(it->second.c_str());
			std::cout << itBtc->second * toMultInt << std::endl;
		}
		else
		{
			toMultFloat = atof(it->second.c_str());
			std::cout << itBtc->second * toMultFloat << std::endl;
		}
	}
	else
	{
		std::cout << " No value find" << std::endl;
	}
}

// check parsing and add to the map // manque de checker le nombre max de jour
int BitcoinExchange::checkIt(std::string save)
{
	bool compa = false;
	for (size_t i = 0; i < save.length() ; i++)
	{
		if ((i < 4 && !isdigit(save[i])) || atoi(save.substr(0, 4).c_str()) < 1000)
		{
			std::cout << " Error: bad input => " << save.substr(0, 10) << std::endl;
			return (-1);
		}
		else if ((i == 4 && save[i] != '-' ) || (i == 7 && save[i] != '-') || (i == 11 && save[i] != '|'))
		{
			std::cout << "Error: bad input => " << save.substr(0, 11) << std::endl;
			return (-1);
		}
		else if (i >= 5 && i <= 6)
		{
			if (!isdigit(save[i]))
				return (std::cout << "Error: bad input => " << save.substr(0, 10)<< std::endl, -1);
			else
			{
				if (atoi(save.substr(5, 6).c_str()) > 12 || atoi(save.substr(5, 6).c_str()) < 1)
					return (std::cout << "Error: bad input => " << save.substr(0, 10)<< std::endl, -1);

			}
		}
		else if (i >= 8 && i <= 9)
		{
			if (!isdigit(save[i]))
				{
					std::cout << "Error: bad input => " << save.substr(0, 10)<< std::endl;;
					return (-1);
				}
				else
				{
					if (atoi(save.substr(8, 9).c_str()) > 31)
						return (std::cout << "Error: bad input => " << save.substr(0, 10)<< std::endl, -1);
				}
		}
		else if(i >= 13)
		{
			size_t posVirg = save.find('.');
			if (posVirg == std::string::npos)
			{
				for (size_t a = i; a < save.length(); a++)
					if (!isdigit(save[a]))
						return (std::cout << "Error: not a positive number.=> " << save.substr(13, save.length())<< std::endl, -1);
				long int toMult = atoi(save.substr(13, save.length()).c_str());
				if (toMult > 1000 || toMult < 0)
					return (std::cout << "Error: Number too big => " << save.substr(13, save.length())<< std::endl, -1);
				_toStock[save.substr(0, 10)] = save.substr(13, save.length());
				return (0);
				// stock tomutl in a vec
			}
			else
			{
				for (size_t a = i; a < save.length(); a++)
				{
					if (!isdigit(save[a]) && save[a] == ',' && compa != true)
					{
						std::cout << "bugged here" << std::endl;
						return (std::cout << "Error: bad input => " << save.substr(13, save.length())<< std::endl, -1) ;
					}
					if (save[a] == ',')
						compa = true;
				}
				float toMult = atof(save.substr(13, save.length()).c_str());
				if (toMult > 1000.0 || toMult < 0)
					return (std::cout << "Error: Number too big => " << save.substr(13, save.length())<< std::endl, -1);
				_toStock[save.substr(0, 10)] = save.substr(13, save.length());
				return (0);
					// stock tomutl in a vec
			}
		}
	}
	return (0);
}

