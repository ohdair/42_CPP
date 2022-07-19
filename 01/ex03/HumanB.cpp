/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:23 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/18 14:03:43 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL) {
}

HumanB::~HumanB(void) {}

void HumanB::attack(void) const {
    if (weapon) 
    {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
    else 
    {
        std::cout << name << " attacks whith bare hands" << std::endl;
    }
}

Weapon& HumanB::getWeapon(void) const {
    return (*weapon);
}

void HumanB::setWeapon(Weapon& newWeapon) {
    weapon = &newWeapon;
}