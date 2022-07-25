/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:48:11 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/23 17:47:51 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int Form::maxGrade = 1;
int Form::minGrade = 150;

Form::Form(void) : name("Test Form"), gradeToSign(150), gradeToExecute(150), sign(false)
{
    std::cout << CLRYEL << "Form" << CLREND << *this << CLRYEL << "has been constructed" << CLREND << std::endl;
    // std::cout << CLRYEL << "Form has been constructed" << CLREND << std::endl;
}
Form::Form(std::string fileName, int GradeToSign, int GradeToExecute) : name(fileName), gradeToSign(GradeToSign), gradeToExecute(GradeToExecute), sign(false)
{
    if (gradeToSign > minGrade || gradeToExecute > minGrade) {
        throw (Form::GradeTooLowException());
    } else if (gradeToSign < maxGrade || gradeToExecute < maxGrade) {
        throw (Form::GradeTooHighException());
    }
    std::cout << CLRYEL << "Form" << CLREND << *this << CLRYEL << "has been constructed" << CLREND << std::endl;
}
Form::~Form(void)
{
    std::cout << "Form has beed destroyed" << std::endl;
}
Form::Form(const Form& form) : name(form.getName()), gradeToSign(form.getGradeToSign()), gradeToExecute(form.getGradeToExecute()), sign(form.getSign()) {}
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

void Form::beSigned(Bureaucrat& bureaucrat)
{
    int grade = bureaucrat.getGrade();

    if (grade > this->gradeToSign)
    {
        throw (Form::GradeTooLowException());
    } else {
        this->sign = true;
        std::cout << *this << "\nBureaucrat " << CLRGRE << bureaucrat.getName() << CLREND
        << "'s Grade is " << CLRYEL << bureaucrat.getGrade() << CLREND << std::endl;
    }
}

const char* Form::Exception::what() const throw()
{
    std::string error("FormException\n");
    error.insert(0, CLRRED).append(CLREND);
    const char *newError = error.c_str();
	return (newError);
}

const char* Form::GradeTooLowException::what() const throw()
{
    std::string error("the grade is too low\n");
    error.insert(0, CLRRED).append(CLREND);
    const char *newError = error.c_str();
	return (newError);
}

const char* Form::GradeTooHighException::what() const throw()
{
    std::string error("the grade is too high\n");
    error.insert(0, CLRRED).append(CLREND);
    const char *newError = error.c_str();
	return (newError);
};

const char* Form::BeSignedFormException::what() const throw()
{
    std::string error("Already be signed\n");
    error.insert(0, CLRRED).append(CLREND);
    const char *newError = error.c_str();
	return (newError);
};

const char* Form::UnsignedFormException::what() const throw()
{
    std::string error("Cannot execute an unsigned form\n");
    error.insert(0, CLRRED).append(CLREND);
    const char *newError = error.c_str();
	return (newError);
};

std::ostream &operator<<(std::ostream &os, const Form& form)
{
    os << "\n Form\t\t\t: " << CLRVIO << form.getName() << CLREND
    << "\n grade_to_sign\t\t: " << CLRVIO << form.getGradeToSign() << CLREND
    << "\n grade_to_execute\t: "<< CLRVIO << form.getGradeToExecute() << CLREND
    << "\n signed equal to\t: " << CLRYEL << form.getSign() << CLREND << "\n";
    return os;
}