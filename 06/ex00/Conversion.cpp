/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:41:57 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/25 16:08:23 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(std::string string) : origin(string) {}
Conversion::Conversion(const Conversion& conversion) : origin(conversion.origin) {}
Conversion::~Conversion(void) {}
Conversion& Conversion::operator=(const Conversion& conversion)
{
    this->origin = conversion.origin;
    return *this;
}

Conversion::TYPE Conversion::getType(void) const
{
    if (this->origin.empty()) return ERROR;
    if (isInt()) return INT;
    if (isFloat()) return FLOAT;
    if (isDouble()) return DOUBLE;
    if (this->origin.size() == 1 && isprint(this->origin[0])) return CHAR;
    return ERROR;
}

bool Conversion::isInt(void) const
{
    long tmp;
    char *pEnd;

    tmp = strtol(this->origin.c_str(), &pEnd, 10);
    if (*pEnd != '\0') return false;
    if (std::numeric_limits<int>::max() < tmp) return false;
    if (std::numeric_limits<int>::min() > tmp) return false;
    return true;
}

bool Conversion::isFloat(void) const
{
    float tmp;
    char *pEnd;
    std::size_t found;

    if ((this->origin == "+inff" || this->origin == "-inff") || this->origin == "nanf") return true;
    tmp = (float)strtod(this->origin.c_str(), &pEnd);
    found = this->origin.find('f');
    if (found == std::string::npos) return false;
    if (*pEnd != 'f' || found != origin.size() - 1) return false;
    return true;
}

bool Conversion::isDouble(void) const
{
    double tmp;
    char *pEnd;
    std::size_t found;

    if ((this->origin == "+inf" || this->origin == "-inf") || this->origin == "nan") return true;
    tmp = (double)strtod(this->origin.c_str(), &pEnd);
    found = this->origin.find('.');
    if (found == std::string::npos) return false;
    if (*pEnd != '\0') return false;
    return true;
}

void Conversion::convert(TYPE type)
{
    char retChar = '\0';
    std::string errorChar("");
    int retInt = 0;
    std::string errorInt("");
    float retFloat = 0.0f;
    std::string errorFloat("");
    double retDouble = 0.0;
    std::string errorDouble("");
    std::string setPrecision("");

    switch(type)
    {
        case CHAR:
            retChar = convertToChar(CHAR);
            try {
                retInt = convertToInt(CHAR);
            } catch (Exception &e) {
                errorInt = e.what();
            }
            retFloat = convertToFloat(CHAR);
            retDouble = convertToDouble(CHAR);
            break;
        case INT:
            try {
                retInt = convertToInt(INT);
            } catch (Exception &e) {
                errorInt = e.what();
            }
            try {
                retChar = convertToChar(INT);
            } catch (Exception &e) {
                errorChar = e.what();
            }
            retFloat = convertToFloat(INT);
            retDouble = convertToDouble(INT);
            break;
        case FLOAT:
            retFloat = convertToFloat(FLOAT);
            try {
                retChar = convertToChar(FLOAT);
            } catch (Exception &e) {
                errorChar = e.what();
            }
            try {
                retInt = convertToInt(FLOAT);
            } catch (Exception &e) {
                errorInt = e.what();
            }
            retDouble = convertToDouble(FLOAT);
            break;
        case DOUBLE:
            retDouble = convertToDouble(DOUBLE);
            try {
                retChar = convertToChar(DOUBLE);
            } catch (Exception &e) {
                errorChar = e.what();
            }
            try {
                retInt = convertToInt(DOUBLE);
            } catch (Exception &e) {
                errorInt = e.what();
            }
            retFloat = convertToFloat(DOUBLE);
            break;
        default:
            errorChar = "impossible";
            errorInt = "impossible";
            errorFloat = "impossible";
            errorDouble = "impossible";
            break;
    }
    /* double & float
        (정수부 + 소수부).size <= 6, 소수부가 0과 동일하면 정수와 같이 표현됨
        예시를 들어보면 1234.001은 1234로 표시가 되나 (int)1234와 같지 않음
        (정수부 + 소수부).size > 6, 부동소수점으로 표현
    */
    std::cout << "char: ";
    (errorChar == "") ? (std::cout << "'" << retChar << "'\n") : (std::cout << errorChar << "\n");
    std::cout << "int: ";
    ((errorInt == "") ? (std::cout << retInt) : (std::cout << errorInt)) << "\n";
    std::cout << "float: ";
    ((errorFloat == "") ? (std::cout << std::fixed << std::setprecision(1) << retFloat << "f") : (std::cout << errorFloat)) << "\n";
    std::cout << "double: ";
    ((errorDouble == "") ? (std::cout << std::fixed << std::setprecision(1) << retDouble) : (std::cout << errorDouble)) << "\n";
}

char Conversion::convertToChar(TYPE type)
{
    double tmp;

    if (type == CHAR)
        return this->origin[0];
    tmp = strtod(this->origin.c_str(), NULL);
    if (!isascii((int)tmp))
        throw Conversion::ImpossibleException();
    if (!isprint((int)tmp))
        throw Conversion::NotPrintException();
    return static_cast<char>(tmp);
}

int Conversion::convertToInt(TYPE type)
{
    double d = strtod(this->origin.c_str(), NULL);
    long tmp = static_cast<long>(d);
    
    // double 에서 long으로 변환 하면서 nan 은 이미 int limit 을 벗어나는 수라고 확인을 하였습니다.
    // if (std::numeric_limits<double>::quiet_NaN() == d)
    //     throw Conversion::ImpossibleException();
    if (std::numeric_limits<int>::max() < tmp || std::numeric_limits<int>::min() > tmp)
        throw Conversion::ImpossibleException();
    if (type == CHAR)
        return static_cast<int>(this->origin[0]);
    return static_cast<int>(tmp);
}

float Conversion::convertToFloat(TYPE type)
{
    float tmp = static_cast<float>(strtod(this->origin.c_str(), NULL));
    if (type == CHAR)
        return static_cast<float>(this->origin[0]);
    return tmp;
}

double Conversion::convertToDouble(TYPE type)
{
    double tmp = strtod(this->origin.c_str(), NULL);
    if (type == CHAR)
        return static_cast<double>(this->origin[0]);
    return tmp;
}

const char* Conversion::Exception::what() const throw()
{
	return ("ConversionException");
}

const char* Conversion::ImpossibleException::what() const throw()
{
	return ("impossible");
}

const char* Conversion::NotPrintException::what() const throw()
{
	return ("Non displayable");
};

// std::ostream &operator<<(std::ostream &os, const Conversion& conversion)
// {
//     if (conversion.getType() == Conversion::CHAR)
//         os << "CHAR";
//     else if (conversion.getType() == Conversion::INT)
//         os << "INT";
//     else if (conversion.getType() == Conversion::FLOAT)
//         os << "FLOAT";
//     else if (conversion.getType() == Conversion::DOUBLE)
//         os << "DOUBLE";
//     else
//         os << "ERROR";
//     return os;
// }