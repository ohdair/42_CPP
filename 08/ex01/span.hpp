/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:13:48 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/28 21:13:26 by jaewpark         ###   ########.fr       */
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
        int longestSpan();
        int shortestSpan();

        std::vector<int> getVector() const;
        unsigned int getContents() const;
    private:
        unsigned int contents;
        std::vector<int> myVector;
};

std::ostream & operator<<(std::ostream & o, Span const & span);

#endif