/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:04:01 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/14 15:33:28 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

unsigned int ClapTrap::_max_hp = 100;
unsigned int ClapTrap::_max_energy = 10;

// Orthodox canonical class form
ClapTrap::ClapTrap(std::string name) : _name(name), _hp(50), _energy(10), _damage(10) {}
ClapTrap::ClapTrap(const ClapTrap& clone)
{
    *this = clone;
}
ClapTrap::~ClapTrap(void) {}
ClapTrap& ClapTrap::operator=(const ClapTrap& clone)
{
    this->_name = clone._name;
    this->_energy = clone._energy;
    this->_hp = clone._hp;
    this->_damage = clone._damage;

    return *this;
}

// Utility function
void ClapTrap::attack(const std::string& target)
{
    if (this->_hp == 0) {
        COUT << CLRRED << "💀 " << this->_name << " was already dead 💀\n" << CLREND;
    } else if (this->_energy == 0) {
        this->_no_energy = this->_damage;
        this->_damage = 0;
        COUT << "🚨 " << this->_name << " has no energy to attack 🚨\n";
    } else {
        if (this->_energy > 0) {
            --this->_energy;
        }
        COUT << "🪓 " << this->_name << " attacked " << target << " 🪓\n";
    }
    COUT << "\n";
    
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::string energyBar("");
    std::string energyStat("");

    if (this->_hp == 0) {
        COUT << CLRRED << "💀 " << this->_name << " was already dead 💀\n" << CLREND;
    } else if (amount == 0) {
        COUT << "😜 " << this->_name << " dodged attack 😜\n";
    } else {
        COUT << "🤕 " << this->_name << " was taken " << amount << " Damage 🤕\n";
        if (this->_hp <= amount) {
            COUT << CLRRED << "💀 " << this->_name << " dead 💀\n" << CLREND;
            this->_hp = 0;
        } else {
            this->_hp -= amount;
            if (this->_hp < 30) {
                energyStat = CLRRED;
            } else if (this->_hp < 60) {
                energyStat = CLRYEL;
            } else {
                energyStat = CLRGRE;
            }
            COUT << "Current HP is  " << energyStat;
            for (unsigned int i = 0; i < (this->_hp / 10); i++)
                energyBar += "▌";
            COUT << energyBar << CLREND;
            for (unsigned int i = 0; i < 10 - (this->_hp / 10); i++)
                COUT << "▌";
            COUT << "  " << energyStat << this->_hp << CLREND << "/" << _max_hp << "\n\n";
        }
    }
    COUT << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::string energyBar("");

    if (this->_hp == 0) {
        COUT << CLRRED << "💀 " << this->_name << " was already dead 💀\n" << CLREND;
    } else if (amount == 0) {
        COUT << "😜 " << this->_name << " took a medicine 💊 that didn't work 😜\n";
    } else {
        COUT << "💊 " << this->_name << " healed 💊\n";
        if (this->_hp < 30) {
            energyBar += CLRRED;
        } else if (this->_hp < 60) {
            energyBar += CLRYEL;
        } else {
            energyBar += CLRGRE;
        }
        for (unsigned int i = 0; i < (this->_hp / (unsigned int)10); i++)
            energyBar += "▌";
        COUT << energyBar << CLREND;
        for (unsigned int i = 0; i < 10 - (this->_hp / (unsigned int)10); i++)
            COUT << "▌";
        COUT << " >>> Heal " << amount << " >>> ";
        energyBar = "";
        if (this->_hp + amount >= _max_hp) {
            this->_hp = _max_hp;
        } else {
            this->_hp += amount;
        }
        if (this->_hp < 30) {
            energyBar += CLRRED;
        } else if (this->_hp < 60) {
            energyBar += CLRYEL;
        } else {
            energyBar += CLRGRE;
        }
        for (unsigned int i = 0; i < (this->_hp / (unsigned int)10); i++)
            energyBar += "▌";
        COUT << energyBar << CLREND;
        for (unsigned int i = 0; i < 10 - (this->_hp / (unsigned int)10); i++)
            COUT << "▌";
        COUT << "\n";
    }
    COUT << "\n";
}

// increase Energy + 2
void ClapTrap::addEnergy(void)
{
    if (this->_energy + 2 >= _max_energy) {
        this->_energy = _max_energy;
    } else {
        if (this->_energy == 0)
            this->_damage = this->_no_energy;
        this->_energy += 2;
        COUT << this->_name << " increase 2 Energy\n";
    }
}

void ClapTrap::getStatus(void) const
{
    std::string energyBar;
    std::string energyStat;

    COUT << "Name is " << this->_name << "\n";
    COUT << "Attack Damage is " << this->getDamage() << "\n";
    COUT << "Current Energy is " << this->getEnergy() << "\n";
    if (this->_hp < 30) {
        energyStat = CLRRED;
    } else if (this->_hp < 60) {
        energyStat = CLRYEL;
    } else {
        energyStat = CLRGRE;
    }
    COUT << "Current HP is  " << energyStat;
    for (unsigned int i = 0; i < (this->_hp / 10); i++)
        energyBar += "▌";
    COUT << energyBar << CLREND;
    for (unsigned int i = 0; i < 10 - (this->_hp / 10); i++)
        COUT << "▌";
    COUT << "  " << energyStat << this->_hp << CLREND << "/" << _max_hp << "\n\n";
}

unsigned int ClapTrap::getHp(void) const { return this->_hp; }
unsigned int ClapTrap::getEnergy(void) const { return this->_energy; }
unsigned int ClapTrap::getDamage(void) const { return this->_damage; }

void ClapTrap::setHp(unsigned int const amount)
{
    if (amount > _max_hp) {
        COUT << "MAX HP is " << _max_hp << "\n";
        this->_hp = _max_hp;
    } else {
        this->_hp = amount;
    }
}

void ClapTrap::setEnergy(unsigned int const amount)
{
    if (amount > _max_energy) {
        COUT << "MAX Energy is " << _max_energy << "\n";
        this->_energy = _max_energy;
    } else {
        this->_energy = amount;
    }
}

void ClapTrap::setDamage(unsigned int const amount)
{
    this->_damage = amount;
}

unsigned int ClapTrap::getMaxHp(void)
{
    return _max_hp;
}
