/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:41:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/25 15:20:26 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <limits> // limits check
# include <cstdlib> // isprint 인쇄 가능 함수 확인
# include <iomanip> // 소수점 제한

class Conversion
{
    public:
        enum TYPE {
            ERROR, CHAR, INT, FLOAT, DOUBLE
        };

        Conversion(std::string string);
        Conversion(const Conversion& conversion);
        ~Conversion();
        Conversion& operator=(const Conversion& conversion);

        TYPE getType(void) const;
        
        bool isInt(void) const;
        bool isFloat(void) const;
        bool isDouble(void) const;

        void convert(TYPE type);
        char convertToChar(TYPE type);
        int convertToInt(TYPE type);
        float convertToFloat(TYPE type);
        double convertToDouble(TYPE type);

        class Exception : public std::exception
        {
            public:
            virtual const char* what() const throw ();
        };

        class ImpossibleException : public Exception
        {
            public:
            const char* what() const throw ();
        };

        class NotPrintException : public Exception
        {
            public:
            const char* what() const throw ();
        };
    private:
        std::string origin;
};

// std::ostream &operator<<(std::ostream &os, const Conversion& conversion);

#endif