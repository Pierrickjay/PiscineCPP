/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:25:27 by pjay              #+#    #+#             */
/*   Updated: 2023/05/10 18:04:14 by pjay             ###   ########.fr       */
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
		~Fixed(void);
		float toFloat(void) const;
		int	toInt(void) const;
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& file, const Fixed& fixed);
#endif
