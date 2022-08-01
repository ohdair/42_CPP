/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:13:48 by jaewpark          #+#    #+#             */
/*   Updated: 2022/08/01 15:24:16 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <iostream>
# include <iterator>
# include <cmath>

class Span
{
    public:
        Span(unsigned int n);
        Span(const Span& span);
        ~Span();
        Span& operator=(const Span& span);

        void addNumber(int number);
        template<typename T>
        void addNumber(T begin, T end);
        int longestSpan();
        int shortestSpan();

        std::vector<int> getVector() const;
        unsigned int getContents() const;
    private:
        unsigned int contents;
        std::vector<int> myVector;
};

std::ostream & operator<<(std::ostream & o, Span const & span);

template<typename T>
void Span::addNumber(T begin, T end)
{
    try {
        if (std::distance(begin, end) + myVector.size() > this->getContents() ) {
            throw (std::out_of_range("\e[91mMore than Span capacity\e[0m"));
        }
        while (begin != end)
            myVector.push_back(*begin++);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
};

#endif