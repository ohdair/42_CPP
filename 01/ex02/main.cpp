/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 08:20:41 by jaewpark          #+#    #+#             */
/*   Updated: 2022/06/20 08:26:09 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
    std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Address of string\t: " << &string << std::endl;
	std::cout << "Address of stringPTR\t: " << stringPTR << std::endl;
	std::cout << "Address of stringREF\t: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of string\t\t\t: " << string <<std::endl;
	std::cout << "Value pointed to by stringPTR\t: " << *stringPTR <<std::endl;
	std::cout << "Value of stringREF\t\t: " << stringREF <<std::endl;

    return (0);
}