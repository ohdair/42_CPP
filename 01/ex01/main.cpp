/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:19:11 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/18 13:57:24 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie* horde;
    int hordeNumber = 10;
    
    horde = zombieHorde(hordeNumber, "Dark Seeker");
    delete [] horde;
    horde = zombieHorde(0, "fail");
    return (0);
}