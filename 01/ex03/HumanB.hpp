/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:50:03 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/20 12:50:03 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB {
    public:
        HumanB(std::string name, Weapon &weapon);
        ~HumanB(void);

        void attack(void) const;
        Weapon &getWeapon(void) const;
        void setWeapon(Weapon &newWeapon);
    private:
        std::string name;
        Weapon &weapon;
}

#endif