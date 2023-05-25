/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:22:58 by pjay              #+#    #+#             */
/*   Updated: 2023/05/24 14:15:46 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private :
		AMateria*	_inventory[4];
	public :
		MateriaSource();
		MateriaSource(const MateriaSource& materiaSource);
		MateriaSource& operator =(const MateriaSource& materiaSource);
		~MateriaSource();
		void learnMateria(AMateria *mat);
		AMateria* createMateria(std::string const & type);
};
