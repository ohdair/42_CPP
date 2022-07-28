/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:29:16 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/27 17:13:10 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <stdint.h>

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

int main()
{
    Data temp("Hello World!");

    std::uintptr_t sirial = serialize(&temp);
    Data* data = deserialize(sirial);
    std::cout << &temp << std::endl;
    std::cout << data << std::endl;

    std::cout << temp.getData() << std::endl;
    std::cout << (*data).getData() << std::endl;
    return 0;
}