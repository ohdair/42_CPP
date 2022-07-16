/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:21:01 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/16 16:26:45 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "Dilige et fac quod vis ";
    std::cout << "The brain 🧠 is full of ideas 💡" << std::endl;
}

Brain::Brain(const Brain& brain)
{
    *this = brain;
    std::cout << "The brain 🧠 capies" << std::endl;
}

Brain::~Brain(void)
{
    delete [] this->ideas;
    std::cout << "Erase your brain 🧠" << std::endl;
}

Brain& Brain::operator=(const Brain& brain)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
    return *this;
}

std::string *Brain::getIdieas(void) const
{
    return this->ideas;
}