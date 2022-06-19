/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:57:13 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/20 07:29:59 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie  stack_zombie("\e[96mStack Zombie");
    Zombie  *heap_zombie = newZombie("\e[92mHeap Zombie");

    randomChump("\e[95mRandom Chump Zombie");
    delete heap_zombie;
    return (0);
}