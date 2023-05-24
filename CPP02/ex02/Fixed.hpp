/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:25:27 by pjay              #+#    #+#             */
/*   Updated: 2023/05/12 09:36:32 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_fixedPointVal;
		static const int _numbFracBits = 8;
	public:
		Fixed(void);
		Fixed(const int val);
		Fixed(const float number);
		Fixed(const Fixed& fixed);
		Fixed& operator= (const Fixed& fixed);
		float operator+ (const Fixed& fixed);
		float operator* (const Fixed& fixed);
		float operator- (const Fixed& fixed);
		float operator/ (const Fixed& fixed);
		int operator> (const Fixed& fixed) const;
		//const signifie que cela modif pas les valeurs a l'interieur et donc permet dappeler la fonction sur des objets constants
		int operator< (const Fixed& fixed) const;
		int operator>= (const Fixed& fixed) const;
		int operator<= (const Fixed& fixed) const;
		int operator== (const Fixed& fixed) const;
		int operator!= (const Fixed& fixed) const;
		static Fixed& min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed& max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
		Fixed operator++(int);//post Increment
		Fixed& operator++(void);// pre Increment
		Fixed operator--(int);//post decrement
		Fixed& operator--(void);// pre decrement
		~Fixed(void);
		float toFloat(void) const;
		int	toInt(void) const;
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& file, const Fixed& fixed);
#endif
