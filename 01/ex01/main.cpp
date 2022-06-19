/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:19:11 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/20 08:01:03 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie* horde;
    int hordeNumber = 10;
    
    horde = zombieHorde(hordeNumber, "Dark Seeker");
    for (int i = 0; i < hordeNumber; i++) {
        horde[i].announce();
    }
    delete [] horde;
    horde = zombieHorde(0, "fail");
    return (0);
}