/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:08:00 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/20 12:08:00 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
    public:
        Weapon(void);
        Weapon(std::string weaponName);
        void setType(std::string weaponName);
        std::string getType(void) const;
    private:
        std::string weapon;
}

#endif