/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:08:00 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/21 18:50:58 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
    public:
        Weapon(void);
        Weapon(std::string weapon);
        void setType(std::string weapon);
        std::string getType(void) const;
    private:
        std::string weapon;
};

#endif