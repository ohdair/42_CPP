/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:17:07 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/20 13:32:23 by jaewpark         ###   ########.fr       */
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

        class GradeTooHighException : virtual public Exception
        {
            public:
            const char* what() const throw ();
        };

        class GradeTooLowException : virtual public Exception
        {
            public:
            const char* what() const throw ();
        };

        // ex01
        void signForm(Form& form);
    private:
        std::string name;
        int grade;
        static int maxGrade;
        static int minGrade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat& bureaucrat);

#endif