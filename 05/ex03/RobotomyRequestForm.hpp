/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:13:20 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/23 18:59:42 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOROMYREQUESTFORM_HPP
# define ROBOROMYREQUESTFORM_HPP

# include "Form.hpp"
# include <cstdlib>


class RobotomyRequestForm : public Form
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(const RobotomyRequestForm& form);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm& form);

        std::string getTarget(void) const;
        void execute(Bureaucrat const & executor) const;
        
        class RobotomyRequestFormException : public Exception
        {
            public:
            const char* what() const throw ();
        };
    private:
        std::string target;
        static int rSign;
        static int rExec;
};

#endif