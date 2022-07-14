#include "ClapTrap.hpp"

// Orthodox canonical class form
ClapTrap::ClapTrap(std::string name) : _name(name) {};
ClapTrap::ClapTrap(const ClapTrap& clone)
{
    *this = clone;
}
ClapTrap::~ClapTrap();
ClapTrap& ClapTrap::operator=(const ClapTrap& clone)
{
    this->_name = clone._name;
    this->_energy = clone._energy;
    this->_hp = clone._hp;
    this->_damage = clone._damage;

    return *this;
}

// Utility function
void attack(const std::string& target)
{
    if (_hp == 0) {
        COUT << _name << " was already dead 🪦\n";
    }
    COUT << 
}
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
void getStatus();