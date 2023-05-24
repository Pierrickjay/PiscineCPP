/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:26:34 by pjay              #+#    #+#             */
/*   Updated: 2023/05/12 09:37:57 by pjay             ###   ########.fr       */
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

int Fixed::operator> (const Fixed& fixed) const
{
	if (this->toFloat() > fixed.toFloat())
		return (1);
	else
		return (0);
}
int Fixed::operator< (const Fixed& fixed) const
{
	if (this->toFloat() < fixed.toFloat())
		return (1);
	else
		return (0);
}

int Fixed::operator>= (const Fixed& fixed) const
{
	if (this->toFloat() >= fixed.toFloat())
		return (1);
	else
		return (0);
}

int Fixed::operator<= (const Fixed& fixed) const
{
	if (this->toFloat() <= fixed.toFloat())
		return (1);
	else
		return (0);
}

int Fixed::operator== (const Fixed& fixed) const
{
	if (this->toFloat() == fixed.toFloat())
		return (1);
	else
		return (0);
}

int Fixed::operator!= (const Fixed& fixed) const
{
	if (this->toFloat() != fixed.toFloat())
		return (1);
	else
		return (0);
}

float Fixed::operator+ (const Fixed& fixed)
{
	float x = (float)(this->toFloat() + fixed.toFloat());
	return x;
}

float Fixed::operator* (const Fixed& fixed)
{
	float x = (float)(this->toFloat() * fixed.toFloat());
	return x;
}
float Fixed::operator- (const Fixed& fixed)
{
	float x = (float)(this->toFloat() - fixed.toFloat());
	return x;
}

float Fixed::operator/ (const Fixed& fixed)
{
	float x = (float)(this->toFloat() / fixed.toFloat());
	return x;
}

Fixed Fixed::operator++(int) // post increment
{
	Fixed tmp(*this);
	++(_fixedPointVal);
	return tmp;
}

Fixed& Fixed::operator++(void) // pre increment
{
	(_fixedPointVal)++;
	return *this;
}
Fixed Fixed::operator--(int) //post decrement
{
	Fixed tmp(*this);
	--(_fixedPointVal);
	return tmp;
}
Fixed& Fixed::operator--(void) // pre decrement
{
	(_fixedPointVal)--;
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//1 << _numbFracBits Cela revient à multiplier 1 par 2 élevé à la puissance de _numbFracBits
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

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.toFloat() < fixed2.toFloat())
		return fixed1;
	else
		return fixed2;
}
const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.toFloat() < fixed2.toFloat())
		return fixed1;
	else
		return fixed2;
}
Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.toFloat() > fixed2.toFloat())
		return fixed1;
	else
		return fixed2;
}
const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.toFloat() > fixed2.toFloat())
		return fixed1;
	else
		return fixed2;
}
