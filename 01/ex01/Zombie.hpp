/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:19:18 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/20 07:56:59 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
    private:
        std::string zombieName;
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void setName(std::string name);
        void announce(void) const;
};

Zombie* zombieHorde(int N, std::string name);

#endif