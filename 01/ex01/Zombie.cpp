/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:19:15 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/20 08:06:45 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string s): zombieName(s) {
    announce();
};

void Zombie::announce(void) const {
    std::cout << zombieName << "\e[90m : "<< "\e[93mBraiiiiiiinnnzzzZ...\e[m" << std::endl;
}

void Zombie::setName(std::string name) {
    zombieName = name;
}

Zombie::~Zombie() {
    std::cout << zombieName << "\e[90m : "<< "\e[93mis Buuuuu...\e[m" << std::endl;
};