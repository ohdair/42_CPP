/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:19:22 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/18 13:57:19 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N < 1) {
		std::cout << "\e[91mA Horde can not contain less than 1 Zombie.\e[m" << std::endl;
		return (NULL);
	}
    Zombie *horde = new Zombie[N];
    if (horde == NULL) {
        std::cout << "\e[91mAllocation of the horde failed.\e[m" << std::endl;
		return (NULL);
    }
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
        horde[i].announce();
    }
    return (horde);
}