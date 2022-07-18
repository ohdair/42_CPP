/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:30:59 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/18 13:15:09 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
    std::string name("Dog");
    this->_type = CLRGRE + name + CLREND;
    std::cout << this->getType() << " was constructed\n";
}

Dog::Dog(const Dog& dog): Animal()
{
    this->_type = dog._type;
}

Dog::~Dog(void)
{
    std::cout << this->getType() << " is destroyed\n";
}

Dog& Dog::operator=(const Dog& dog)
{
    this->_type = dog.getType();

    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << this->getType() << " is Bowwow 🐶\n";
}