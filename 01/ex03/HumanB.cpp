/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:23 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/20 13:25:23 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(nullptr) {}

HumanB::~HumanB(void) {}

void HumanB::attack(void) const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

Weapon& HumanB::getWeapon(void) const {
    return (weapon);
}

void setWeapon(Weapon &newWeapon) {
    if (newWeapon.getType)
    weapon = &newWeapon;
}