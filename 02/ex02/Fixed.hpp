/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:39:23 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/13 17:15:53 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;

        // The 6 comparison operators
        bool operator>(const Fixed& fixed) const;
        bool operator<(const Fixed& fixed) const;
        bool operator>=(const Fixed& fixed) const;
        bool operator<=(const Fixed& fixed) const;
        bool operator==(const Fixed& fixed) const;
        bool operator!=(const Fixed& fixed) const;

        // The 4 arithmetic operators
        Fixed operator+(const Fixed& fixed) const;
        Fixed operator-(const Fixed& fixed) const;
        Fixed operator*(const Fixed& fixed) const;
        Fixed operator/(const Fixed& fixed) const;

        // The 4 increment/decrement operators
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed& valueX, Fixed& valueY);
        static const Fixed& min(const Fixed& valueX, const Fixed& valueY);
        static Fixed& max(Fixed& valueX, Fixed& valueY);
        static const Fixed& max(const Fixed& valueX, const Fixed& valueY);

        
    private:
        int value;
        static const int bit = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif