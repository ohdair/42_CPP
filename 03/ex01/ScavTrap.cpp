/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:16:54 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/15 14:30:07 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

unsigned int ScavTrap::_max_hp = 100;
unsigned int ScavTrap::_max_energy = 50;
unsigned int ScavTrap::_default_damage = 20;

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_class_name = "ScavTrap";
    this->_hp = this->_max_hp;
    this->_energy = this->_max_energy;
    this->_damage = this->_default_damage;
    std::string className = this->_class_name;
    COUT << CLRVIO << className << CLREND << " " << this->_name << " has been created\n";
}

ScavTrap::ScavTrap(const ScavTrap& clone) : ClapTrap(clone._name)
{
    *this = clone;
    this->_name = clone._name + " Copy";
    COUT << CLRVIO << this->_class_name << CLREND << " " << this->_name << " has been created\n";
}

ScavTrap::~ScavTrap(void)
{
    COUT << CLRVIO << this->_class_name << CLREND << " " << this->_name << " is destroyed\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& clone)
{
    this->_class_name = clone._class_name;
    this->_name = clone._name;
    this->_energy = clone._energy;
    this->_hp = clone._hp;
    this->_damage = clone._damage;

    return *this;
}

void ScavTrap::attack(const std::string& target)
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

void ScavTrap::guardGate(void)
{
	COUT << CLRVIO << this->_class_name << CLREND << " " << this->_name << " has entered the Gate Keeper mode\n";
	this->setEnergy(this->_max_energy);
	COUT << CLRVIO << this->_class_name << CLREND << " " << this->_name << " has fully recovered his energy points!\n\n";
}