/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:25:02 by pjay              #+#    #+#             */
/*   Updated: 2023/05/12 09:45:09 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	Point a(-8.5, 9.8);
	Point b(2.4, 9.5);
	Point c(1.2, 2.4);
	Point point(1.2, 2.4);

	std::cout << "a x =" << a.getX() << std::endl;
	std::cout << "a y =" << a.getY() << std::endl;
	std::cout << "b x =" << b.getX() << std::endl;
	std::cout << "b y =" << b.getY() << std::endl;
	std::cout << "c x =" << c.getX() << std::endl;
	std::cout << "c y =" << c.getY() << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "inside the triangle" << std::endl;
	else
		std::cout << "outside the triangle" << std::endl;
}

// 10|
// 9|
// 8|
// 7|
// 6|
// 5|
// 4|
// 3|
// 2|
// 1|___________________
// 0 1 2 3 4 5 6 7 8 9 10
