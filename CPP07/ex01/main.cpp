/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:50:30 by pjay              #+#    #+#             */
/*   Updated: 2023/06/17 14:58:33 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int array[4] = {8, 4, 8 ,7};
	const char *chArray[4] = {"ceci est un test", "un autre", "encore un autre", "Le dernier"};

	iter(array, 4, printIt<int>);
	iter(chArray, 4, printIt<const char *>);
}
