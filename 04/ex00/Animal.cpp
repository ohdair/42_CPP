/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:59:29 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/16 16:12:25 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    std::string name("Animal");
    this->_type = CLRVIO + name + CLREND;
    std::cout << this->getType() << " was constructed\n";
}
Animal::Animal(const Animal& animal)
{
    *this = animal;
}
Animal::~Animal(void)
{
    std::cout << this->getType() << " is destroyed\n";
}
Animal& Animal::operator=(const Animal& animal)
{
    this->_type = animal._type;

    return *this;
}

void Animal::makeSound(void) const
{
    std::cout << this->getType() << " is wailing \n";
}

std::string Animal::getType(void) const
{
    return this->_type;
}