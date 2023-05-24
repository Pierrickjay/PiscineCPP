/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:26:34 by pjay              #+#    #+#             */
/*   Updated: 2023/05/11 10:24:58 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPointVal = 0;
}


Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	int x = val << _numbFracBits;
	this->setRawBits(x);
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	int x = roundf(number * (1 << _numbFracBits));
	_fixedPointVal = x;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator= (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_fixedPointVal = fixed.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& file, const Fixed& fixed)
{
	float x = static_cast<float>(fixed.getRawBits()) / (1 << 8);
	file << x;
	return file;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//1 << _numbFracBits Cela revient à multiplier 1 par 2 élevé à la puissance de _numbFracBits
// donc 256bits apres la virgule
float Fixed::toFloat(void) const
{
	float x = static_cast<float>(this->getRawBits()) / (1 << 8);
	return x;
}

int	Fixed::toInt(void) const
{
	return (int)((int)_fixedPointVal / (int)(1 << _numbFracBits));
}

int Fixed::getRawBits(void) const
{
	return (_fixedPointVal);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointVal = raw;
}
