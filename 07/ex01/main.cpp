/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:33:05 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/29 10:01:14 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    std::cout << "========== \e[33mInt Array\e[0m ==========\n";
    int array[] = {7, 27, 42, 142, 242, 342, 442, 1, 2, 3};
    // int array_size = sizeof(array) / sizeof(array[0]);
    int array_size = *(&array + 1) - array;
    
    iter<int>(array, array_size, displayElements);

    std::cout << "\n========== \e[33mString Array\e[0m ==========\n";

    std::string array1[] = {"abc", "def", "ghij", "klmn"};
    int array1_size = sizeof(array1) / sizeof(array1[0]);
    // int array1_size = *(&array1 + 1) - array1;

    iter<std::string>(array1, array1_size, displayElements);
}