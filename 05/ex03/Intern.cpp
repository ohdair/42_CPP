/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:18:47 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/25 20:58:44 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << CLRYEL << "Intern has been constructed" << CLREND << std::endl;
}
Intern::Intern(const Intern& intern)
{
    (void)intern;
}
Intern::~Intern(void)
{
    std::cout << "Intern has beed destroyed" << std::endl;
}
Intern& Intern::operator=(const Intern& intern)
{
    (void)intern;
    return *this;
}

static Form *new_robo(std::string target)
{
    Form *ret = new RobotomyRequestForm(target);
    return ret;
}

static Form *new_pres(std::string target)
{
    Form *ret = new PresidentialPardonForm(target);
    return ret;
}

static Form *new_shru(std::string target)
{
    Form *ret = new ShrubberyCreationForm(target);
    return ret;
}

Form *Intern::makeForm(std::string form_name, std::string form_target)
{
    Form *(*func[3])(std::string target) = {new_robo, new_pres, new_shru};
    std::string targeting[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    Form *ret = NULL;

    for (int i = 0; i < 3; i++) {
        if (targeting[i] == form_name)
            ret = func[i](form_target);
    }
    if (ret) {
        std::cout << "Intern creates " << *ret << std::endl;
    } else {
        throw Intern::Exception();
    }
    return ret;
}

const char* Intern::Exception::what() const throw ()
{
    std::string error("Form not found\n");
    error.insert(0, CLRRED).append(CLREND);
    const char *newError = error.c_str();
	return (newError);
}
