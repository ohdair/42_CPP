/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:35:43 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/18 13:12:10 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    std::string name("Cat");
    this->_type = CLRYEL + name + CLREND;
    std::cout << this->getType() << " was constructed\n";
    this->brain = new Brain;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
    this->_type = cat.getType();
    this->brain = new Brain(*cat.brain);
}

Cat::~Cat(void)
{
    delete this->brain;
    std::cout << this->getType() << " is destroyed\n";
}

Cat& Cat::operator=(const Cat& cat)
{
    this->_type = cat.getType();
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*cat.brain);
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << this->getType() << " is Meow 🐱\n";
}