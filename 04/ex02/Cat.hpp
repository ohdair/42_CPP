/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:30:39 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/18 13:07:51 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    public:
        Cat();
        Cat(const Cat& cat);
        virtual ~Cat();
        Cat& operator=(const Cat& cat);

        virtual void makeSound(void) const;
    private:
        Brain *brain;
};

#endif