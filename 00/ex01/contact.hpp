/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 09:49:05 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/14 13:24:56 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact {
    private : 
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
    public :
        Contact();
        void setFirstName(std::string fn);
        std::string getFirstName();
        void setLastName(std::string ln);
        std::string getLastName();
        void setNickName(std::string nn);
        std::string getNickName();
        void setPhoneNumber(std::string pn);
        std::string getPhoneNumber();
        void setDarkestSecret(std::string ds);
        std::string getDarkestSecret();
        ~Contact();
};