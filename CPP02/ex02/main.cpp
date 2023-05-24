/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:25:02 by pjay              #+#    #+#             */
/*   Updated: 2023/05/12 09:39:52 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	if (b > a)
		std::cout << "b is bigger" << std::endl;
	else
		std::cout << "a is bigger or equal to b" << std::endl;
	if (b == a)
		std::cout << "b is equal to a" << std::endl;
	else
		std::cout << "b is not equal to a" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "max entre a et b est "<< Fixed::max( a, b ) << std::endl;
	std::cout << "min entre a et b est "<<  Fixed::min( a, b ) << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << "decrement" << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << b << std::endl;
	std::cout << "div " << a << " / " << b << " = " << a / b << std::endl;
	std::cout << "mult " << a << " * " << b << " = " << a * b << std::endl;
	std::cout << "addition " << a << " + " << b << " = " << a + b << std::endl;
	std::cout << "soustraction " << a << " - " << b << " = " << a - b << std::endl;
	return 0;
}
