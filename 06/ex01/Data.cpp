/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:18:27 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/25 13:39:28 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : data("Default") {};
Data::Data(std::string input) : data(input) {};
Data::Data(const Data& data) : data(data.getData()) {};
Data::~Data(void) {};
Data& Data::operator=(const Data& data)
{
    this->data = data.getData();
    return *this;
}

std::string Data::getData(void) const 
{
    return this->data;
}