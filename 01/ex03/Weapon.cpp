/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:12:30 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/21 19:29:57 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string weapon) : weapon(weapon) {}

void Weapon::setType(std::string weapon) {
    this->weapon = weapon;
}

std::string Weapon::getType(void) const {
    return weapon;
}