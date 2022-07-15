/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:11:27 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/15 14:34:47 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& clone);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap& clone);

        void attack(const std::string& target);
        void guardGate(void);
    private:
        static unsigned int _max_hp;
        static unsigned int _max_energy;
        static unsigned int _default_damage;
};

#endif