/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:39:21 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/11 20:41:09 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value(value << Fixed::bit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value((int)roundf(value * (1 << Fixed::bit)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed.value;
	return *this;
}

void Fixed::setRawBits(const int raw)
{
	this->value = raw;
}

int Fixed::getRawBits() const
{
	return this->value;
}

float Fixed::toFloat(void) const
{
	return (this->value / (float) (1 << Fixed::bit));
}

int Fixed::toInt(void) const
{
	return (this->value >> Fixed::bit);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}