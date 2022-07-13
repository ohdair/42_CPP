#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    public:
        // Orthodox canonical class form
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& clone);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& clone);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    private:
        std::string Name;
        unsigned int HitPoints;
        unsigned int EnergyPoints;
        unsigned int AttackDamage;
};

#endif