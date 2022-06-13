/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:56:10 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/13 18:38:06 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void printUpperString(char **argv)
{
    std::string y("");
    for (int i = 1; argv[i]; i++)
        while (*argv[i])
            y += toupper(*(argv[i]++));
    std::cout << y << std::endl;
} 

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
        printUpperString(argv);
    return 0;
}