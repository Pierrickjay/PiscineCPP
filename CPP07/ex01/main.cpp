/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:50:30 by pjay              #+#    #+#             */
/*   Updated: 2023/06/21 12:51:35 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
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

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];
  const char *test[] = {"pepe", "test", "test"};

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );
  iter (test, 3, print<const char*>);

  return 0;
}
