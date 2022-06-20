/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:12:30 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/20 12:12:30 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {
    weapon = "Only hand"
}

Weapon::Weapon(std::string weapon) {
    weapon = weapon;
}

void setType(std::string weapon) {
    // "" (공백도 입력이 된다면 맨 주먹으로 세팅)
    weapon = weapon;
}

std::string getType(void) const {
    return weapon;
}