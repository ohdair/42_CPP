/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:17:24 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/25 20:56:18 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "\nConstructed\n==============================" << std::endl;
    Intern doby;
    Form *president;
    Form *robo;
    Form *shrub;
    Form *unknown;

    president = doby.makeForm("presidential pardon", "president");
    robo = doby.makeForm("robotomy request", "robo");
    shrub = doby.makeForm("shrubbery creation", "shrub");
    try {
        unknown = doby.makeForm("WTF", "unknown");
    } catch (Intern::Exception &e) {
        std::cout << e.what();
    }

    delete president;
    delete robo;
    delete shrub;
    return (0);
}