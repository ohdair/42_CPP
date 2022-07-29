/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:26:09 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/29 10:01:25 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) {
    int a = 2;
    int b = 3;

    ::swap<int>( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min<int>( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max<int>( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap<std::string>( c, d );
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min<std::string>( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max<std::string>( c, d ) << std::endl;

    return 0;
}