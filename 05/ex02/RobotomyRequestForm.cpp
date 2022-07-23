/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:10:01 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/23 18:56:31 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

int RobotomyRequestForm::rSign = 72;
int RobotomyRequestForm::rExec = 45;

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Default President Parent", rSign, rExec), target("Default")
{
    std::cout << CLRYEL << "RobotomyRequestForm" << CLREND << *this << CLRYEL << "has been defaultly constructed" << CLREND << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string name) : Form("President Parent", rSign, rExec), target(name)
{
    std::cout << CLRYEL << "RobotomyRequestForm" << CLREND << *this << CLRYEL << "has been constructed" << CLREND << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form) : Form(form.getName(), form.getGradeToSign(), form.getGradeToExecute()), target(form.getTarget())
{
    std::cout << CLRYEL << "RobotomyRequestForm" << CLREND << *this << CLRYEL << "has been copied" << CLREND << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm has beed destroyed" << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
    this->target = form.getTarget();
    return *this;
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return this->target;
}

const char* RobotomyRequestForm::RobotomyRequestFormException::what() const throw()
{
    std::string error("the robotomy failed\n");
    error.insert(0, CLRRED).append(CLREND);
    const char *newError = error.c_str();
	return (newError);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    int percentage = std::rand() % 100;

    if (this->getSign() == false) {
        throw (Form::UnsignedFormException());
    } else if (executor.getGrade() > this->getGradeToExecute()) {
        std::cout << CLRVIO << "Execution failed : " << CLREND << std::endl;
        throw (Form::GradeTooLowException());
    } 
    std::cout << "⛔️ some drilling noises ⛔️" << std::endl;
    if (percentage < 50) {
        throw (RobotomyRequestForm::RobotomyRequestFormException());
    }
    std::cout << this->target << " has been robotomized " << CLRYEL << "successfully 50%" << CLREND << " of the time\n";
}