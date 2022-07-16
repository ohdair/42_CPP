/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:35:43 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/16 14:48:30 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{   
    std::string name("WrongCat");
    this->_type = CLRRED + name + CLREND;
    std::cout << this->getType() << " was constructed\n";
}
WrongCat::WrongCat(const WrongCat& wrongCat) : WrongAnimal(wrongCat)
{
    // *this = wrongCat;
    this->_type = wrongCat.getType();
}
WrongCat::~WrongCat(void)
{
    std::cout << this->getType() << " is destroyed\n";
}
WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
    this->_type = wrongCat.getType();

    return *this;
}

void WrongCat::makeSound(void) const
{
    std::cout << this->getType() << " is Meow 🐱\n";
}

std::string WrongCat::getType(void) const
{
    return this->_type;
}