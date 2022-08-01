/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:14:16 by jaewpark          #+#    #+#             */
/*   Updated: 2022/08/01 15:27:47 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <deque>

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
	std::cout << sp << std::endl;
    std::cout << "Shortest span\t: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span\t: " << sp.longestSpan() << std::endl;

    std::cout << "===============addNumber===============\n";

    Span test(1000);
    std::deque<int> dq;

    // for (int i = 0; i < 1000; i++)
    //     dq.push_back(i);

    // test.addNumber(dq.begin(), dq.end());

    std::cout << test << std::endl;
}