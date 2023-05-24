/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:13:13 by pjay              #+#    #+#             */
/*   Updated: 2023/05/22 13:39:38 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#pragma once


class IMateriaSource
{
	private:
		/* data */
	public:

		IMateriaSource();
		IMateriaSource(const IMateriaSource& iMateriaSource);
		IMateriaSource& operator =(const IMateriaSource& iMateriaSource);
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};
