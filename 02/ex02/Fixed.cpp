/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:39:21 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/13 16:45:59 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) {}
Fixed::Fixed(const int value) : value(value << Fixed::bit) {}
Fixed::Fixed(const float value) : value((int)roundf(value * (1 << Fixed::bit))) {}
Fixed::Fixed(const Fixed& fixed)
{
    *this = fixed;
}
Fixed::~Fixed(void) {}
Fixed& Fixed::operator=(const Fixed& fixed)
{
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

// The 6 comparison operators
bool Fixed::operator>(const Fixed& fixed) const { return (this->value > fixed.value); }
bool Fixed::operator<(const Fixed& fixed) const { return (this->value < fixed.value); }
bool Fixed::operator>=(const Fixed& fixed) const { return (this->value >= fixed.value); }
bool Fixed::operator<=(const Fixed& fixed) const { return (this->value <= fixed.value); }
bool Fixed::operator==(const Fixed& fixed) const { return (this->value == fixed.value); }
bool Fixed::operator!=(const Fixed& fixed) const { return (this->value != fixed.value); }

// The 4 arithmetic operators
Fixed Fixed::operator+(const Fixed& fixed) const
{;
	Fixed ret(this->toFloat() + fixed.toFloat());
	return ret;
}
Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed ret(this->toFloat() - fixed.toFloat());
	return ret;
}
Fixed Fixed::operator*(const Fixed& fixed) const
{
	Fixed ret(this->toFloat() * fixed.toFloat());
	return ret;
}
Fixed Fixed::operator/(const Fixed& fixed) const
{
	if (fixed.value == 0)
		throw fixed;
	Fixed ret(this->toFloat() / fixed.toFloat());
	return ret;
}

// The 4 increment/decrement operators
Fixed& Fixed::operator++()	// Prefix increment operator.
{
	value++;
	return *this;
}
Fixed Fixed::operator++(int)	// Postfix increment operator.
{
	Fixed temp = *this;
	++*this;
	return temp;
}
Fixed& Fixed::operator--()	// Prefix decrement operator.
{
	value--; 
	return *this;
}
Fixed Fixed::operator--(int)	// Postfix decrement operator.
{
	Fixed temp = *this;
	--*this;
	return temp;
}

// min & max
Fixed& Fixed::min(Fixed& valueX, Fixed& valueY)
{
	if (valueX < valueY)
		return valueX;
	return valueY;
}
const Fixed& Fixed::min(const Fixed& valueX, const Fixed& valueY)
{
	if (valueX < valueY)
		return valueX;
	return valueY;
}
Fixed& Fixed::max(Fixed& valueX, Fixed& valueY)
{
	if (valueX > valueY)
		return valueX;
	return valueY;
}
const Fixed& Fixed::max(const Fixed& valueX, const Fixed& valueY)
{
	if (valueX > valueY)
		return valueX;
	return valueY;
}