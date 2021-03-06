/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:03:55 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/15 16:19:12 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::string s1("jaewpark");
    std::string s2("juhur");

    ClapTrap claptrap(s1);
    ScavTrap scavtrap(s2);

    scavtrap.setHp(80);
    claptrap.setEnergy(2);
    claptrap.getStatus();
    scavtrap.getStatus();

    COUT << "-----------------------------\n\n";
    claptrap.attack(s2);
    scavtrap.takeDamage(claptrap.getDamage());
    
    COUT << "-----------------------------\n\n";
    claptrap.setDamage(30);
    claptrap.attack(s2);
    scavtrap.takeDamage(claptrap.getDamage());
    
    COUT << "-----------------------------\n\n";
    claptrap.attack(s2);
    scavtrap.takeDamage(claptrap.getDamage());

    COUT << "-----------------------------\n\n";
    claptrap.addEnergy();
    claptrap.attack(s2);
    scavtrap.takeDamage(claptrap.getDamage());
    
    COUT << "-----------------------------\n\n";
    scavtrap.guardGate();

    COUT << "-----------------------------\n\n";
    scavtrap.attack(s1);
    claptrap.takeDamage(scavtrap.getDamage());

    COUT << "-----------------------------\n\n";
    scavtrap.setDamage(142);
    scavtrap.attack(s1);
    claptrap.takeDamage(scavtrap.getDamage());

    return (0);
}