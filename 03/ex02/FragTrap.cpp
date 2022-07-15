/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:19:21 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/15 16:32:19 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

unsigned int FragTrap::_max_hp = 100;
unsigned int FragTrap::_max_energy = 100;
unsigned int FragTrap::_default_damage = 30;

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_class_name = "FragTrap";
    this->_hp = this->_max_hp;
    this->_energy = this->_max_energy;
    this->_damage = this->_default_damage;
    std::string className = this->_class_name;
    COUT << CLRVIO << className << CLREND << " " << this->_name << " has been created\n";
}

FragTrap::FragTrap(const FragTrap& clone) : ClapTrap(clone._name)
{
    *this = clone;
    this->_name = clone._name + " Copy";
    COUT << CLRVIO << this->_class_name << CLREND << " " << this->_name << " has been created\n";
}

FragTrap::~FragTrap(void)
{
    COUT << CLRVIO << "FragTrap " << CLREND << this->_name << " is destroyed\n";
}

FragTrap& FragTrap::operator=(const FragTrap& clone)
{
    this->_class_name = clone._class_name;
    this->_name = clone._name;
    this->_energy = clone._energy;
    this->_hp = clone._hp;
    this->_damage = clone._damage;

    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (this->_hp == 0) {
        COUT << CLRRED << "💀 " << this->_name << " was already dead 💀\n" << CLREND;
    } else if (this->_energy == 0) {
        this->_no_energy = this->_damage;
        this->_damage = 0;
        COUT << "🚨 " << this->_name << " has no energy to attack 🚨\n";
    } else {
        --this->_energy;
        COUT << "🪓 " << CLRVIO << this->_class_name << CLREND << " " << this->_name << " attacked " << target << " 🪓\n";
        COUT << this->_name << " now has " << this->getEnergy() << " energy points left\n";
    }
    COUT << "\n"; 
}

void FragTrap::highFiveGuys(void)
{
    COUT << CLRVIO << "Who wants to do a high five with " << this->_name << " ?? 🖐\n\n" << CLREND;
}