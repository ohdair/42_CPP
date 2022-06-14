/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 09:04:56 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/14 13:52:48 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
 
PhoneBook::PhoneBook() {
    indexNumber = 0;
}

void PhoneBook::AddContact() {
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    std::cout << "Index : " << indexNumber + 1 << std::endl;
    std::cout << "First Name : ";
    std::getline(std::cin, firstName);
    std::cout << "Last Name : ";
    std::getline(std::cin, lastName);
    std::cout << "NickName : ";
    std::getline(std::cin, nickName);
    std::cout << "Phone Number : ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Darkest Secret : ";
    std::getline(std::cin, darkestSecret);
    memberInfo[indexNumber].setFirstName(firstName);
    memberInfo[indexNumber].setLastName(lastName);
    memberInfo[indexNumber].setNickName(nickName);
    memberInfo[indexNumber].setPhoneNumber(phoneNumber);
    memberInfo[indexNumber].setDarkestSecret(darkestSecret);
    indexNumber++;
}

void PhoneBook::SearchMember() {
    std::cout << "|     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|\n";
    for (int i = indexNumber; i > indexNumber - 8 && i >= 0; i--) {

    }
}