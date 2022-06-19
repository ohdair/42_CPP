/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:23:58 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/17 16:22:11 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
    private:
        const std::string zombieName;
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce(void) const;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif