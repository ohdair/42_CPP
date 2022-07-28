/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:31:01 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/28 21:26:56 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n) : contents(n)
{
    myVector.reserve(n);
}
Span::Span(const Span& span) : contents(span.contents)
{
    if (this->myVector.size())
        this->myVector.clear();
    this->myVector = span.myVector;
}
Span::~Span(void) {}
Span& Span::operator=(const Span& span)
{
    if (this->myVector.size())
        this->myVector.clear();
    this->myVector = span.myVector;
    this->contents = span.contents;
    return *this;
}

void Span::addNumber(int number)
{
    if (this->myVector.size() == this->contents)
        throw (std::out_of_range("\e[91mOut of range\e[0m"));
    myVector.push_back(number);
}

int Span::longestSpan(void)
{
    if (this->myVector.size() <= 1)
        throw (std::out_of_range("\e[91mNot enough elements for a span\e[0m"));
    std::vector<int>::iterator min = std::min_element(myVector.begin(), myVector.end());
    std::vector<int>::iterator max = std::max_element(myVector.begin(), myVector.end());
    return (*max - *min);
}
int Span::shortestSpan(void)
{
    if (this->myVector.size() <= 1)
        throw (std::out_of_range("\e[91mNot enough elements for a span\e[0m"));
    int shortest = INT_MAX;
    std::sort(myVector.begin(), myVector.end());
    for (unsigned int i = 0; i < myVector.size() - 1; i++)
        shortest < std::abs(myVector[i + 1] - myVector[i]) ? shortest : shortest = std::abs(myVector[i + 1] - myVector[i]);
    return shortest;
}

std::vector<int> Span::getVector(void) const
{
    return this->myVector;
}
unsigned int Span::getContents(void) const
{
    return this->contents;
}

std::ostream & operator<<(std::ostream & o, Span const & span)
{
	std::cout << "Span contents\t: ";
	for (unsigned int i = 0; i < span.getContents(); i++)
		std::cout << (span.getVector())[i] << " ";
	std::cout << std::endl;
	return (o);
}