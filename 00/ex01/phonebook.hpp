/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:11:35 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/15 16:13:10 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "contact.hpp"

class PhoneBook {
    private :
        Contact memberInfo[8];
        int indexNumber;
    public :
     PhoneBook();
     void   AddContact();
     void   SearchMember();
     ~PhoneBook();
};