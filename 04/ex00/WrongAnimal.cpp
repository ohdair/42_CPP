/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:59:29 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/16 14:41:29 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::string name("WrongAnimal");
    this->_type = CLRVIO + name + CLREND;
    std::cout << this->getType() << " was constructed\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
{
    *this = wrongAnimal;
}
WrongAnimal::~WrongAnimal(void)
{
    std::cout << this->getType() << " is destroyed\n";
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
    this->_type = wrongAnimal._type;

    return *this;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << this->getType() << " is Bo-Beep 🤖 Bo-Beep 🤖 \n";
}

std::string WrongAnimal::getType(void) const
{
    return this->_type;
}