/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:20:46 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/21 19:29:19 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): name(name), weapon(weapon) {}

HumanA::~HumanA(void) {}

void HumanA::attack(void) const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

Weapon& HumanA::getWeapon(void) const {
    return (weapon);
}