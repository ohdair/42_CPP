/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:39:26 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/13 17:12:23 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    // a = Fixed( 1234.4321f );
        std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
        std::cout << "c is " << c << std::endl;
        std::cout << "d is " << d << std::endl;
        std::cout << "a is " << a.toInt() << " as integer" << std::endl;
        std::cout << "b is " << b.toInt() << " as integer" << std::endl;
        std::cout << "c is " << c.toInt() << " as integer" << std::endl;
        std::cout << "d is " << d.toInt() << " as integer" << std::endl;
        std::cout << "d < b is " << (d < b) << std::endl;
        std::cout << "d > b is " << (d > b) << std::endl;
        std::cout << "d == b is " << (d == b) << std::endl;
        std::cout << "d != b is " << (d != b) << std::endl;
        std::cout << "d <= b is " << (d <= b) << std::endl;
        std::cout << "d >= b is " << (d >= b) << std::endl;
    try {
        std::cout << "b / a is " << (b / a) << std::endl;
    } catch (Fixed exception) {
        std::cerr << "\e[33mERROR\n\e[91m[ Error Message : division by " << exception << " ]\e[0m" << std::endl;
        // return 1;
    }
    Fixed e;
    Fixed const f( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << e << std::endl;
    std::cout << ++e << std::endl;
    std::cout << e << std::endl;
    std::cout << e++ << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;
    std::cout << Fixed::max( e, f ) << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}