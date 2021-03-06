/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 09:04:56 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/17 14:52:52 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
 
PhoneBook::PhoneBook(): indexNumber(0) {}

PhoneBook::~PhoneBook(void) {}

static int printErrorMsg(std::string s) {
    if (std::cin.eof())
        return 1;
    else if (s == "") {
        std::cout << "\e[91m[" << s << "] is invalid value!!\e[m\n";
        return 1;
    }
    return 0;
}

void PhoneBook::AddContact() {
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    std::cout << "Index : " << (indexNumber % 8) + 1 << std::endl;
    std::cout << "First Name : ";
    std::getline(std::cin, firstName);
    if (printErrorMsg(firstName))
        return ;
    std::cout << "Last Name : ";
    std::getline(std::cin, lastName);
    if (printErrorMsg(lastName))
        return ;
    std::cout << "NickName : ";
    std::getline(std::cin, nickName);
    if (printErrorMsg(nickName))
        return ;
    std::cout << "Phone Number : ";
    std::getline(std::cin, phoneNumber);
    if (printErrorMsg(phoneNumber))
        return ;
    std::cout << "Darkest Secret : ";
    std::getline(std::cin, darkestSecret);
    if (printErrorMsg(darkestSecret))
        return ;
    memberInfo[indexNumber % 8].setFirstName(firstName
    );
    memberInfo[indexNumber % 8].setLastName(lastName);
    memberInfo[indexNumber % 8].setNickName(nickName);
    memberInfo[indexNumber % 8].setPhoneNumber(phoneNumber);
    memberInfo[indexNumber % 8].setDarkestSecret(darkestSecret);
    indexNumber++;
}

static std::string printCompressInfo(std::string Info) {
    int infoLength = Info.length();
    std::string ret;

    if (infoLength >= 10) {
        ret = Info.substr(0, 9);
        ret.push_back('.');
    }
    else
        ret = Info;
    return ret;
}

static void printContact(Contact memberInfo, int i) {
    std::cout << "|";
    std::cout << std::setfill(' ') << std::setw(10);
    std::cout << i + 1;
    std::cout << "|";
    std::cout << std::setfill(' ') << std::setw(10);
    std::cout << printCompressInfo(memberInfo.getFirstName());
    std::cout << "|";
    std::cout << std::setfill(' ') << std::setw(10);
    std::cout << printCompressInfo(memberInfo.getLastName());
    std::cout << "|";
    std::cout << std::setfill(' ') << std::setw(10);
    std::cout << printCompressInfo(memberInfo.getNickName());
    std::cout << "|\n";
}

static void printMember(Contact memberInfo) {
    std::cout << "first name : " << memberInfo.getFirstName() << std::endl;
    std::cout << "last name : " << memberInfo.getLastName() << std::endl;
    std::cout << "nickname : " << memberInfo.getNickName() << std::endl;
    std::cout << "phone number : " << memberInfo.getPhoneNumber() << std::endl;
    std::cout << "darkest secret : " << memberInfo.getDarkestSecret() << std::endl;
}

void PhoneBook::SearchMember() {
    std::string indexTmp;
    std::cout << "|     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|\n";
    for (int i = 0; i < indexNumber && i < 8; i++) {
        printContact(memberInfo[i], i);
    }
    std::cout << "Enter Index : ";
    std::getline(std::cin, indexTmp);
    if (std::cin.eof())
        return ;
    if (indexTmp.length() == 1 && indexTmp[0] >= '1' && indexTmp[0] <= '8' && indexTmp[0] <= ('0' + indexNumber))
        printMember(memberInfo[std::atoi(indexTmp.c_str()) - 1]);
    else
        std::cout << "\e[91m[" << indexTmp << "] is invalid index!!\e[m\n";
}