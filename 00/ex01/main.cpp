/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:26:07 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/15 16:08:34 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main() {
    std::string input;
    PhoneBook pb;

    while (1) {
        std::cout << "Available commands: ADD, SEARCH, EXIT\nInput command: ";
        std::getline(std::cin, input);
        if (input == "EXIT" || std::cin.eof()) break;
        else if (input == "ADD") pb.AddContact();
        else if (input == "SEARCH") pb.SearchMember();
        else std::cout << "[" << input << "] is invalid command!!\n";
    }
    std::cout << "Exit" << std::endl;
}