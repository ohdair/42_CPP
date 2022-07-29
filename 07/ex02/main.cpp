/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:28:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/29 09:58:21 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

// random function
#include <cstdlib>
#include <ctime>

#define YELLOW "\e[33m"
#define CLREND "\e[0m"
#define MAX_VAL 10
int main(int, char**)
{
    std::cout << "========================= " << YELLOW << "Constructed" << CLREND <<  " =========================\n";
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(std::time(NULL));
    std::cout << "========================= " << YELLOW << "Data  input" << CLREND <<  " =========================\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }


    std::cout << "\n========================= " << YELLOW << "Array  copy" << CLREND <<  " =========================\n";
    Array<int> tmp = numbers;
    Array<int> test(tmp);

    std::cout << "========================== " << YELLOW << "Exception" << CLREND <<  " ==========================\n";
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n========================= " << YELLOW << "Data  input" << CLREND <<  " =========================\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();
    }
    std::cout << "\n========================== " << YELLOW << "Destryoed" << CLREND <<  " ==========================\n";
    delete [] mirror;
    return 0;
}