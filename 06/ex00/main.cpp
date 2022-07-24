/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:35:05 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/24 20:10:18 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
        return 1;
    std::string input = argv[1];
    Conversion trans(input);
    trans.convert(trans.getType());
    std::cout << trans;
    return 0;
}