/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:13:06 by pjay              #+#    #+#             */
/*   Updated: 2023/06/15 16:53:50 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "idUtils.hpp"
#include "C.hpp"

int main()
{
	Base *ptr = NULL;
	ptr = generate();
	identify(ptr);
	identify(*ptr);
	free(ptr);
	ptr = new A;
	identify(ptr);
	free(ptr);
	ptr = generate();
	identify(ptr);
	identify(*ptr);

}
