 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:48:30 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/16 16:33:33 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    cat->makeSound();
    delete cat;
    delete dog;
    system("leaks Brain");

    std::cout << std::endl;
    std::cout << "========== Next ==========" << std::endl;
    std::cout << std::endl;

    const Animal* animals[20];
    for (int i = 0; i < 10; i++) {
        std::cout << CLRVIO << i << " " << CLREND;
        animals[i] = new Cat();
    }
    for (int i = 10; i < 20; i++) {
        std::cout << CLRVIO << i << " " << CLREND;
        animals[i] = new Dog();
    }
    for (int i = 0; i < 20; i++) {
        std::cout << CLRVIO << i << " " << CLREND;
        delete animals[i];
    }
    system("leaks Brain");

    std::cout << std::endl;
    std::cout << "========== Next ==========" << std::endl;
    std::cout << std::endl;

    Cat originCat;
    
    Cat &refCat = originCat;
    Cat copyCat(originCat);

    std::cout << std::hex << &originCat << std::endl;
    std::cout << std::hex << &refCat << std::endl;
    std::cout << std::hex << &copyCat << std::endl;

    system("leaks Brain");

    return 0;
}