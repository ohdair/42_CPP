/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:03:48 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/15 10:13:25 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define COUT std::cout
# define CLRRED "\e[91m"
# define CLRGRE "\e[92m"
# define CLRYEL "\e[93m"
# define CLRVIO "\e[95m"
# define CLREND "\e[0m"

# include <iostream>
# include <iomanip>

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

        void addEnergy(void);
        void getStatus(void);
        unsigned int getHp(void) const;
        unsigned int getEnergy(void) const;
        unsigned int getDamage(void) const;
        void setHp(unsigned int const amout);
        void setEnergy(unsigned int const amout);
        void setDamage(unsigned int const amout);
        
        void draw(unsigned int hp);

        static unsigned int getMaxHp(void);
    private:
        std::string _name;
        unsigned int _hp;
        unsigned int _energy;
        unsigned int _damage;
        unsigned int _no_energy;

        static unsigned int _max_hp;
        static unsigned int _max_energy;
};

#endif