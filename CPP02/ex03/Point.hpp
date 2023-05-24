/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:30:02 by pjay              #+#    #+#             */
/*   Updated: 2023/05/11 14:17:54 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public :
		Point(void);
		Point(const float x, const float y);
		Point(const Point& fixed);
		Point& operator= (const Point& point);
		Fixed getX(void) const;
		Fixed getY(void) const;
		~Point(void);
};

float getW1(Point const a, Point const b, Point const c, Point const point);
float getW2(Point const a, Point const b, Point const c, Point const point);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
