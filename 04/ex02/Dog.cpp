/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:30:59 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/18 13:10:10 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
    std::string name("Dog");
    this->_type = CLRGRE + name + CLREND;
    std::cout << this->getType() << " was constructed\n";
    this->brain = new Brain;
}

Dog::Dog(const Dog& dog): Animal()
{
    this->_type = dog.getType();
    this->brain = new Brain(*dog.brain);
}

Dog::~Dog(void)
{
    delete this->brain;
    std::cout << this->getType() << " is destroyed\n";
}

Dog& Dog::operator=(const Dog& dog)
{
    this->_type = dog.getType();
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*dog.brain);
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << this->getType() << " is Bowwow 🐶\n";
}