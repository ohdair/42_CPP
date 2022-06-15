/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:18:23 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/15 13:35:07 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {
    _firstName = "";
    _lastName = "";
    _nickName = "";
    _phoneNumber = "";
    _darkestSecret = "";
}

Contact::~Contact(void) {}

void Contact::setFirstName(std::string fn) {
    _firstName = fn;
}

std::string Contact::getFirstName() {
    return _firstName;
}

void Contact::setLastName(std::string ln) {
    _lastName = ln;
}

std::string Contact::getLastName() {
    return _lastName;
}

void Contact::setNickName(std::string nn) {
    _nickName = nn;
}

std::string Contact::getNickName() {
    return _nickName;
}

void Contact::setPhoneNumber(std::string pn) {
    _phoneNumber = pn;
}

std::string Contact::getPhoneNumber() {
    return _phoneNumber;
}

void Contact::setDarkestSecret(std::string ds) {
    _darkestSecret = ds;
}

std::string Contact::getDarkestSecret() {
    return _darkestSecret;
}
