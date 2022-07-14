/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:03:55 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/14 17:17:01 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    // HP MAX : 100, ENERGY MAX : 10;
    std::string s1("jaewpark");
    std::string s2("juhur");

    ClapTrap claptrap1(s1);
    ClapTrap claptrap2(s2);

    claptrap2.setHp(80);
    claptrap1.setEnergy(2);
    claptrap1.getStatus();
    claptrap2.getStatus();

    COUT << "-----------------------------\n\n";
    claptrap1.setDamage(15);
    claptrap1.attack(s2);
    claptrap2.takeDamage(claptrap1.getDamage());
    
    COUT << "-----------------------------\n\n";
    claptrap1.attack(s2);
    claptrap2.takeDamage(claptrap1.getDamage());
    
    COUT << "-----------------------------\n\n";
    claptrap1.attack(s2);
    claptrap2.takeDamage(claptrap1.getDamage());

    COUT << "-----------------------------\n\n";
    claptrap1.addEnergy();
    claptrap1.setDamage(30);
    claptrap1.attack(s2);
    claptrap2.takeDamage(claptrap1.getDamage());
    
    COUT << "-----------------------------\n\n";
    claptrap2.beRepaired(ClapTrap::getMaxHp());

    COUT << "-----------------------------\n\n";
    claptrap2.setDamage(142);
    claptrap2.attack(s1);
    claptrap1.takeDamage(claptrap2.getDamage());

    return (0);
}