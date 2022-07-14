#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define COUT std::cout 
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

        void getStatus();
        █
    private:
        std::string _name;
        unsigned int _hp;
        unsigned int _energy;
        unsigned int _damage;
};

#endif