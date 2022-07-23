/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:10:01 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/23 18:56:17 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

int PresidentialPardonForm::pSign = 25;
int PresidentialPardonForm::pExec = 5;

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Default President Pardon", pSign, pExec), target("Default")
{
    std::cout << CLRYEL << "PresidentialPardonForm" << CLREND << *this << CLRYEL << "has been defaultly constructed" << CLREND << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string name) : Form("President Pardon", pSign, pExec), target(name)
{
    std::cout << CLRYEL << "PresidentialPardonForm" << CLREND << *this << CLRYEL << "has been constructed" << CLREND << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form) : Form(form.getName(), form.getGradeToSign(), form.getGradeToExecute()), target(form.getTarget())
{
    std::cout << CLRYEL << "PresidentialPardonForm" << CLREND << *this << CLRYEL << "has been copied" << CLREND << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm has beed destroyed" << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form)
{
    this->target = form.getTarget();
    return *this;
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() == false) {
        throw (Form::UnsignedFormException());
    } else if (executor.getGrade() > this->getGradeToExecute()) {
        std::cout << CLRVIO << "Execution failed : " << CLREND << std::endl;
        throw (Form::GradeTooLowException());
    }
    std::cout << this->target << " was pardonned by Zafod Beeblebrox\n";
}