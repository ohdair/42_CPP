/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:07:50 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/28 17:44:32 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <array>

int main(void)
{
    std::cout << "----------------------- \e[33mlist\e[0m ---------------------" << std::endl;
    std::list<int> lst;
    for (int i = 1; i <= 5; i++)
        lst.push_back(i * 10);

    std::cout << easyfind(lst, 50) << std::endl; // will return the iterator to "50"
    try {
        std::cout << easyfind(lst, -28) << std::endl;
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------------------------" << std::endl << std::endl;
    std::cout << "----------------------- \e[33mArray\e[0m ---------------------" << std::endl;
    std::array<int, 5> array;
    for (int i = 1; i <= 5; i++)
        array[i - 1] = i * 7;

    std::cout << easyfind(array, 14) << std::endl; // will return the iterator to "50"
    try {
        std::cout << easyfind(array, -28) << std::endl;
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------------------------" << std::endl << std::endl;
    return (0);
}