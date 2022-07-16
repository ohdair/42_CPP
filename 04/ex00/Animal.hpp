/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:49:29 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/16 16:29:59 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# define CLRRED "\e[91m"
# define CLRGRE "\e[92m"
# define CLRYEL "\e[93m"
# define CLRVIO "\e[95m"
# define CLREND "\e[0m"

# include <iostream>

class Animal
{
    public:
        Animal();
        Animal(const Animal& animal);
        virtual ~Animal();
        Animal& operator=(const Animal& animal);

        virtual void makeSound(void) const;
        std::string getType(void) const;
    protected:
        std::string _type;
};

#endif