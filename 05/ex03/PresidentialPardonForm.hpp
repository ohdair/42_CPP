/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Presidentialpardonform.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:13:20 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/23 16:58:19 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(const PresidentialPardonForm& form);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm& form);

        std::string getTarget(void) const;
        void execute(Bureaucrat const & executor) const;
        
    private:
        std::string target;
        static int pSign;
        static int pExec;
};

#endif