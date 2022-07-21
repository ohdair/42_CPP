/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:48:11 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/20 16:46:32 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("anonymous"), gradeToSign(150), gradeToExecute(150), sign(false) {}
Form::~Form(void) {}
Form::Form(const Form& form) : name(form.getName()), gradeToSign(form.getGradeToSign()), gradeToExecute(form.getGradeToExecute()), sign(form.getSign())
{
}
Form& Form::operator=(const Form& form)
{
    if (this != &form)
        this->sign = form.sign;
    return *this;
}

const std::string Form::getName() const { return this->name; }
int Form::getGradeToSign() const { return this->gradeToSign; }
int Form::getGradeToExecute() const { return this->gradeToExecute; }
bool Form::getSign() const { return this->sign; }
void Form::setSign(const bool newSign) { this->sign = newSign; }

void beSigned(Bureaucrat& bureaucrat);