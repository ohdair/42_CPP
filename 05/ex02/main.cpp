/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:17:24 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/23 18:55:02 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // Constructors
    std::cout << "\nConstructed\n==============================" << std::endl;
    Bureaucrat  oracle("Oracle", 1);
    Bureaucrat  java("Java", 139);

    ShrubberyCreationForm   shrub("shrub");
    RobotomyRequestForm     robo("robo");
    PresidentialPardonForm  president("president");


    std::cout << "\nShrubberyCreationForm\n==============================" << std::endl;
    java.executeForm(shrub);
    shrub.beSigned(java);
    java.executeForm(shrub);

    std::cout << "\nRobotomyRequestForm\n==============================" << std::endl;
    java.executeForm(robo);
    try {
        robo.beSigned(java);
    } catch (Form::Exception& e) {
        std::cout << e.what() << std::endl;
    }
    robo.beSigned(oracle);
    try {
        oracle.executeForm(robo);
        oracle.executeForm(robo);
        oracle.executeForm(robo);
        oracle.executeForm(robo);
        oracle.executeForm(robo);
    } catch (Form::Exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nPresidentialPardonForm\n==============================" << std::endl;
    oracle.executeForm(president);
    president.beSigned(oracle);
    oracle.executeForm(president);

    std::cout << "DESTRUCTORS:" << std::endl;
    std::cout << "----------------------------" << std::endl;
    return (0);
}