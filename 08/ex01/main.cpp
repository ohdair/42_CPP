/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:14:16 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/28 21:27:11 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main(void)
{
    Span sp(5);

    try {
        sp.addNumber(5);
        std::cout << "Shortest span\t: " << sp.shortestSpan() << std::endl; // Error
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(14); // Error
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << sp;
    std::cout << "Shortest span\t: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span\t: " << sp.longestSpan() << std::endl;
}