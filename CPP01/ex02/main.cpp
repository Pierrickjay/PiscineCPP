/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:36:00 by pjay              #+#    #+#             */
/*   Updated: 2023/05/06 15:16:17 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using std::string;

int main()
{
	string brain[17] = {"HI THIS IS BRAIN"};
	string &stringREF = brain[0];
	string *stringPTR = &stringREF;

	std::cout << "address : "<< brain << std::endl;
	std::cout << "address : "<< &stringPTR << std::endl;
	std::cout << "address : "<< &stringREF << std::endl;
	std::cout << " Value : " << brain[0] << std::endl;
	std::cout << " Value : " << *stringPTR << std::endl;
	std::cout << " Value : " << stringREF << std::endl;
}
