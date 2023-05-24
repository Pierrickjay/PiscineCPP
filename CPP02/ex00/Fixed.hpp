/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:50:06 by pjay              #+#    #+#             */
/*   Updated: 2023/05/09 13:57:16 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	_fixedPointVal;
		static const int _numbFracBits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& fixed);
		Fixed& operator= (const Fixed& fixed);
		~Fixed(void);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
