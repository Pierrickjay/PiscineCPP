/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:56:06 by pjay              #+#    #+#             */
/*   Updated: 2023/08/11 14:21:29 by pjay             ###   ########.fr       */
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
	int i = 0;

	try
	{
		ExcRate.open("data.csv");
		toBuy.open(av);
		if (!ExcRate.is_open() || !toBuy.is_open())
			throw std::ios_base::failure("File not found");
		fillMap(ExcRate);
		while (std::getline(toBuy, save))
		{
			if ( i == 0 && save != "date | value")
			{
				std::cout << "Error: Wrong format" << std::endl;
				return ;
			}
			else if (i == 0)
			{
				i++;
				continue ;
			}
			if (checkIt(save) == -1)
				continue ;
			else
			{
				printSwap();
				_toStock.clear();
			}
		}
	}
	catch(std::ios_base::failure& e)
	{
		ExcRate.close();
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
			closeDate = it->first.substr(0, 4);
		}
	}
	for (std::map<std::string, float>::iterator it = btcValue.begin(); it != btcValue.end(); it++)
	{
		int numToEx = atoi(itToEx->first.substr(5, 2).c_str());
		int numBtc = atoi(it->first.substr(5, 2).c_str());

		if (closeDate == it->first.substr(0, 4))
		{
			if (numBtc <= numToEx )
			{
				tmp = it->first.substr(4, 4);
			}
		}
	}
	closeDate += tmp;
	for (std::map<std::string, float>::iterator it = btcValue.begin(); it != btcValue.end(); it++)
	{
		int numToEx = atoi(itToEx->first.substr(8, 2).c_str());
		int numBtc = atoi(it->first.substr(8, 2).c_str());
		if (closeDate == it->first.substr(0, 8))
		{
			if (numBtc <= numToEx)
				tmp = it->first.substr(8, 2);
		}
	}
	closeDate += tmp;
	return (closeDate);
}

int isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return (1);
	else
		return (0);
}

int checkMonthday(std::string date)
{
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (year < 2009)
		return (-1);
	if (month > 12 || month < 1)
		return (-1);
	if (month == 2 && day > 28 && !isLeapYear(year))
		return (-1);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (-1);
	else
	{
		if (day > 31 || day < 1)
			return (-1);
	}
	return (0);
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
	if (save.length() <= 13)
	{
		std::cout << "Error: bad input => " << save.substr(0, 10) << std::endl;
		return (-1);
	}
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
					if (checkMonthday(save.substr(0, 10)) == -1)
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
			}
		}
	}
	return (0);
}

