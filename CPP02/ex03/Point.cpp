/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:29:45 by pjay              #+#    #+#             */
/*   Updated: 2023/05/11 14:36:44 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

//les constructors sont commenter car illisible
Point::Point(void) : x(Fixed(0)), y(Fixed(0))
{
	//std::cout << "Constructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y))
{
	std::cout << "Constructor called" << std::endl;
}

Point:: Point(const Point& point) : x(point.getX()), y(point.getY())
{
	//std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator= (const Point& point)
{
	if (this != &point)
	{
		(Fixed)this->x = point.getX();
		(Fixed)this->y = point.getY();
	}
	return *this;
}

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}

Point::~Point(void)
{
	//std::cout << "constructor called" << std::endl;
}
// la formule est expliquer sur la video
// Gamedev Maths: point in triangle
float getW1(Point const a, Point const b, Point const c, Point const point)
{
	float w1;

	w1 = a.getX() * (c.getY() - a.getY()) + (point.getY() - a.getY()) * (c.getX() - a.getX()) - point.getX() * (c.getY() - a.getY());
	w1 /= (b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX())* (c.getY() - a.getY());
	std::cout << "w1 = " << w1 << std::endl;
	return (w1);
}

float getW2(Point const a, Point const b, Point const c, Point const point, float w1)
{
	float w2;

	w2 = point.getY() - a.getY() - w1 * (b.getY() - a.getY());
	w2 /= c.getY() - a.getY();
	std::cout << "w2 = " << w2 << std::endl;
	return (w2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float w1 = getW1(a, b, c, point);
	float w2 = getW2(a, b, c, point, w1);


	if (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1)
		return true;
	else
		return false;
}
