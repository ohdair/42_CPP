/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:33:23 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/20 07:31:18 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void) const {
    std::cout << zombieName << "\e[90m : "<< "\e[93mBraiiiiiiinnnzzzZ...\e[m" << std::endl;
}

Zombie::Zombie(std::string s): zombieName(s) {
    announce();
};

Zombie::~Zombie() {
    std::cout << zombieName << "\e[90m : "<< "\e[93mis Buuuuu...\e[m" << std::endl;
};