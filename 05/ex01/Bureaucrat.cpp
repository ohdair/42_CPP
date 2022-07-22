/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:17:04 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/22 14:04:13 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int Bureaucrat::maxGrade = 1;
int Bureaucrat::minGrade = 150;

Bureaucrat::Bureaucrat(void) : name("anonymous"), grade(minGrade)
{
    std::cout << "Bureaucrat\n" << *this << CLRYEL << "has been constructed" << CLREND << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade > this->minGrade) {
        throw (Bureaucrat::GradeTooHighException());
    } else if (grade < this->maxGrade) {
        throw (Bureaucrat::GradeTooLowException());
    } else {
        this->grade = grade;
        std::cout << "Bureaucrat\n" << *this << CLRYEL << "has been constructed" << CLREND << std::endl;
    }
}
Bureaucrat::Bureaucrat(const Bureaucrat& origin)
{
    this->name = origin.getName();
    this->grade = origin.getGrade();
}
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat has beed destroyed" << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& origin)
{
    this->name = origin.getName();
    this->grade = origin.getGrade();
    return *this;
}

void Bureaucrat::incrementGrade(void)
{
    if (this->grade <= this->maxGrade) {
        throw (Bureaucrat::GradeTooHighException());
    } else {
        --this->grade;
    }
    std::cout << CLRYEL << this->name << CLREND << " increase " << CLRVIO << 1 << CLREND << " notch to " << CLRGRE << this->grade << CLREND << " grade\n";
}

void Bureaucrat::decrementGrade(void)
{
    if (this->grade >= this->minGrade) {
        throw (Bureaucrat::GradeTooLowException());
    } else {
        ++this->grade;
    }
    std::cout << CLRYEL << this->name << CLREND << " decrease " << CLRVIO << 1 << CLREND << " notch to " << CLRGRE << this->grade << CLREND << " grade\n";
}

const std::string Bureaucrat::getName(void) const { return this->name; }
int Bureaucrat::getGrade(void) const { return this->grade; }
void Bureaucrat::setGrade(const int grade)
{
    if (grade > this->minGrade) {
        throw (Bureaucrat::GradeTooLowException());
    } else if (grade < this->maxGrade) {
        throw (Bureaucrat::GradeTooHighException());
    } else {
        this->grade = grade;
    }
}

void Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << CLRGRE << this->getName() << CLRYEL << " signed " << CLREND << form << "\n";
    } catch (Form::Exception& e){
        std::cout << CLRGRE << this->getName() << CLRRED << " couldn't sign " << CLREND << form << CLRYEL << "because " << CLREND << e.what() << "\n";
    }
}

const char* Bureaucrat::Exception::what() const throw()
{
    std::string error("BureaucratException\n");
    error.insert(0, CLRRED).append(CLREND);
    const char *newError = error.c_str();
    return newError;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    std::string error("The grade cannot be higher than 1\n");
    error.insert(0, CLRRED).append(CLREND);
    const char *newError = error.c_str();
    return newError;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    std::string error("The grade cannot be lower than 150\n");
    error.insert(0, CLRRED).append(CLREND);
    const char *newError = error.c_str();
    return newError;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat& bureaucrat)
{
    os << " " << CLRYEL << bureaucrat.getName() << CLREND << ", bureaucrat grade " << CLRGRE << bureaucrat.getGrade() << CLREND << ".\n";
    return os;
}