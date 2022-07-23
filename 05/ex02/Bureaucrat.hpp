/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:17:07 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/23 17:16:51 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define CLRRED "\e[91m"
# define CLRGRE "\e[92m"
# define CLRYEL "\e[93m"
# define CLRVIO "\e[95m"
# define CLREND "\e[0m"

# include <iostream>
# include <exception>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& origin);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& origin);

        void incrementGrade(void);
        void decrementGrade(void);

        const std::string getName(void) const;
        int getGrade(void) const;
        void setGrade(const int grade);
        
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

        // ex01
        void signForm(Form& form);

        // ex02
        void executeForm(Form const & form);
    private:
        const std::string name;
        int grade;
        static int maxGrade;
        static int minGrade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat& bureaucrat);

#endif