/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:07:15 by pjay              #+#    #+#             */
/*   Updated: 2023/06/15 14:28:35 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	_name = "default";
	std::cout << YELLOW " Constructor of Data Called" RESET<< std::endl;
}

Data::Data(std::string name)
{
	_name = name;
	std::cout << YELLOW " Constructor of Data Called" RESET<< std::endl;
}

Data::Data(const Data& rhs)
{
	_name = rhs._name;
	std::cout << YELLOW " Constructor by assignement of Data Called" RESET<< std::endl;
}

Data& Data::operator= (const Data& rhs)
{
	std::cout << YELLOW " Constructor by assignement operator of Data Called" RESET<< std::endl;
	_name = rhs._name;
	return *this;
}

Data::~Data()
{
	std::cout << YELLOW " Destructor of Data Called" RESET<< std::endl;
}

std::string Data::getName()
{
	return (_name);
}

