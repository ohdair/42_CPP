/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:19:18 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/15 14:47:28 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& clone);
        ~FragTrap();
        FragTrap& operator=(const FragTrap& clone);

        void attack(const std::string& target);
        void highFiveGuys(void);
    private:
        static unsigned int _max_hp;
        static unsigned int _max_energy;
        static unsigned int _default_damage;
};

#endif
