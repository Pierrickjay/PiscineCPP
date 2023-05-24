/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:54:30 by pjay              #+#    #+#             */
/*   Updated: 2023/04/15 18:01:06 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl name;

	std::cout << "calling the debug function" << std::endl;
	name.complain("debug");
	std::cout << "calling the info function" << std::endl;
	name.complain("info");
	std::cout << "calling the warning function" << std::endl;
	name.complain("warning");
	std::cout << "calling the error function" << std::endl;
	name.complain("error");
	std::cout << "calling weirdthing function" << std::endl;
	name.complain("weirdthing");
}
