/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:17:24 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/23 14:18:09 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    // Constructors
    std::cout << "\nConstructed\n==============================" << std::endl;
    Bureaucrat  oracle("Oracle", 1);
    Bureaucrat  java("Java", 132);

    Bureaucrat & oracle_ref = oracle;
    Bureaucrat & java_ref = java;

    Form        a("A13", 4, 6);
    Form        b("B97", 146, 135);

    // Create a Form with grades too low
    try {
        Form    c("C46", 489, 1435);
    } catch (Form::Exception &e) {
        std::cout << "Constructor failure: " << e.what() << std::endl;
    }

    // Create a grade with grades too high
    try {
        Form    c("D143", -583, -800);
    } catch (Form::Exception &e) {
        std::cout << "Constructor failure: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Sign forms
    std::cout << "\nSIGN FORM\n==============================" << std::endl;

    // Sign OK
    std::cout << "SIGN OK:" << std::endl;
    oracle_ref.signForm(a);
    std::cout << "just showed its current status" << a << std::endl;
    // a.setSign(false);
    std::cout << std::endl << std::endl;

    // Sign KO
    std::cout << "SIGN KO:" << std::endl;
    java_ref.signForm(a);
    std::cout << "just showed its current status" << a <<  std::endl;
    std::cout << std::endl << std::endl;

    // Sign KO
    std::cout << "SIGN KO:" << std::endl;
    oracle.signForm(a);
    std::cout << "just showed its current status" << a << std::endl;
    std::cout << std::endl;

    // Sign KO
    std::cout << "SIGN OK:" << std::endl;
    oracle.signForm(b);
    std::cout << "just showed its current status" << b << std::endl;
    std::cout << std::endl;

    std::cout << "DESTRUCTORS:" << std::endl;
    std::cout << "----------------------------" << std::endl;
    return (0);
}