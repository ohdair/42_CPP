/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:17:24 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/23 14:08:33 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\nConstructed\n==============================" << std::endl;
    Bureaucrat hummanA("jaewpark", 139);
    Bureaucrat hummanB("polarBear", 3);
    Bureaucrat hummanC;
    try {
        Bureaucrat hummanD("taeng", 160);
    } catch (Bureaucrat::Exception &e) {
        std::cout << e.what();
    }
    Bureaucrat hummanE(hummanA);
    Bureaucrat hummanF;

    hummanF = hummanB;

    std::cout << "\n\nBureaucrat Info\n==============================" << std::endl;
    std::cout << hummanA;
    std::cout << hummanB;
    std::cout << hummanC;
    std::cout << hummanE;
    std::cout << hummanF;

    std::cout << "\n\nBureaucrat Test\n==============================" << std::endl;
    try{
        hummanB.incrementGrade();
        hummanB.incrementGrade();
        hummanB.incrementGrade();
        hummanB.incrementGrade();
    } catch (Bureaucrat::Exception &e) {
        std::cout << e.what();
    }
    
    try {
        hummanA.setGrade(12746891);
        hummanA.setGrade(-3);
    } catch (Bureaucrat::Exception &e) {
        std::cout << e.what();
    }

    return 0;
}