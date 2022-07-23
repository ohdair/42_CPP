/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:48:07 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/23 15:38:00 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(std::string fileName, int gradeToSign, int gradeToExecute);
        Form(const Form& form);
        ~Form();
        Form& operator=(const Form& form);

        const std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getSign() const;
        void setSign(const bool newSign);

        void beSigned(Bureaucrat& bureaucrat);
        
        class Exception : public std::exception
        {
            public:
            virtual const char* what() const throw ();
        };

        class GradeTooHighException : public Exception
        {
            public:
            const char* what() const throw ();
        };

        class GradeTooLowException : public Exception
        {
            public:
            const char* what() const throw ();
        };

        class BeSignedFormException : public Exception
        {
            public:
            const char* what() const throw ();
        };
        
        // ex02
        class UnsignedFormException : public Exception
        {
            public:
            const char* what() const throw ();
        };
        
        // ex02
        virtual void execute(Bureaucrat const & executor) const = 0;
    private:
        const std::string name;
        const int gradeToSign;
        const int gradeToExecute;
        bool sign;
        static int maxGrade;
        static int minGrade;
};

std::ostream &operator<<(std::ostream &os, const Form& form);

# endif