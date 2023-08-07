/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:50:30 by pjay              #+#    #+#             */
/*   Updated: 2023/07/11 15:49:39 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
// a supp
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
	std::cout << x << std::endl;
	return;
}
//

int main() {
	float x = float();
	std::cout << x << std::endl;
	int	array1[] = {1, 2, 3, 4, 5};
	iter(array1, 5, &printIt<int>);
	std::cout << std::endl;
	iter(array1, 8, &printIt<int>);
	std::cout << std::endl;

	char	array2[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	iter(array2, 7, &printIt<char>);
	std::cout << std::endl;
	iter(array2, 9, &printIt<char>);
	std::cout << std::endl;

	float	array3[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	iter(array3, 5, &printIt<float>);
	std::cout << std::endl;
	iter(array3, 50, &printIt<float>);
	std::cout << std::endl;

	return 0;
}
