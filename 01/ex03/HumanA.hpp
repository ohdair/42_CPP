/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:20:51 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/21 19:29:14 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {
    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA(void);

        void attack(void) const;
        Weapon& getWeapon(void) const;
        // void setWeapon(Weapon &weapon);
    private:
        std::string name;
        Weapon& weapon;
};

#endif