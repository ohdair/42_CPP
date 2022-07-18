/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:27:25 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/18 13:07:54 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
    public:
        Dog();
        Dog(const Dog& dog);
        virtual ~Dog();
        Dog& operator=(const Dog& dog);

        virtual void makeSound(void) const;
    private:
        Brain *brain;
};

#endif