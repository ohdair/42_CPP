/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:17:24 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/19 15:46:38 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat hummanA("jaewpark", 139);
    Bureaucrat hummanB("polarBear", 3);
    Bureaucrat hummanC;

    std::cout << hummanA;
    std::cout << hummanB;
    std::cout << hummanC;

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