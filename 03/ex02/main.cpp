/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:03:55 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/15 15:04:48 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::string s1("jaewpark");
    std::string s2("juhur");
    std::string s3("jim");

    ClapTrap claptrap(s1);
    ScavTrap scavtrap(s2);
    FragTrap fragtrap(s3);

    claptrap.getStatus();
    scavtrap.getStatus();
    fragtrap.getStatus();

    COUT << "-----------------------------\n\n";
    claptrap.attack(s2);
    scavtrap.takeDamage(claptrap.getDamage());
    
    COUT << "-----------------------------\n\n";
    fragtrap.attack(s1);
    claptrap.takeDamage(fragtrap.getDamage());
    
    COUT << "-----------------------------\n\n";
    claptrap.setDamage(60);
    claptrap.attack(s2);
    scavtrap.takeDamage(claptrap.getDamage());

    COUT << "-----------------------------\n\n";
    scavtrap.setDamage(80);
    scavtrap.attack(s3);
    fragtrap.takeDamage(scavtrap.getDamage());
    
    COUT << "-----------------------------\n\n";
    scavtrap.guardGate();

    COUT << "-----------------------------\n\n";
    fragtrap.highFiveGuys();

    COUT << "-----------------------------\n\n";
    scavtrap.setDamage(142);
    scavtrap.attack(s1);
    claptrap.takeDamage(scavtrap.getDamage());

    return (0);
}