/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:49:29 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/16 14:34:46 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# define CLRRED "\e[91m"
# define CLRGRE "\e[92m"
# define CLRYEL "\e[93m"
# define CLRVIO "\e[95m"
# define CLREND "\e[0m"

# include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& wrongAnimal);
        ~WrongAnimal();
        WrongAnimal& operator=(const WrongAnimal& wrongAnimal);

        void makeSound(void) const;
        std::string getType(void) const;
    private:
        std::string _type;
};

#endif