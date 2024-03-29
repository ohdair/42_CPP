/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:19:24 by jaewpark          #+#    #+#             */
/*   Updated: 2022/08/01 17:16:11 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>


template<typename T>
typename T::iterator easyfind(T& first, const int second)
{
    typename T::iterator ret;
    try {
        ret = std::find(first.begin(), first.end(), second);
        if (ret == first.end())
            throw (std::out_of_range("\e[91mNot found\e[0m ("));
        return ret;
    } catch(std::exception &e) {
        std::cerr << e.what() << second << ")\t: ";
    }
    return ret;
};

#endif