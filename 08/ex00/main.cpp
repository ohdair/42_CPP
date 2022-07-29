/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:07:50 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/29 11:48:21 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>

int main(void)
{
    std::cout << "----------------------- \e[33mlist\e[0m ---------------------" << std::endl;
    std::list<int> lst;
    for (int i = 1; i <= 5; i++)
        lst.push_back(i * 10);

    std::cout << *easyfind(lst, 50) << std::endl; // will return the iterator to "50"
    std::cout << *easyfind(lst, -28) << std::endl; // ERROR
    std::cout << "Vector End\t: " << *(lst.end()) << std::endl;
    std::cout << "\n---------------------- \e[33mVector\e[0m --------------------" << std::endl;
    std::vector<int> vector;
    for (int i = 1; i <= 5; i++)
        vector.push_back(i * 7);

    std::cout << *easyfind(vector, 14) << std::endl; // will return the iterator to "14"
    std::cout << *easyfind(vector, -28) << std::endl; // ERROR
    std::cout << "Vector End\t: " << *(vector.end()) << std::endl;
    std::cout << "--------------------------------------------------" << std::endl << std::endl;
    return (0);
}