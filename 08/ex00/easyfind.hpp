/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:19:24 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/28 17:44:51 by jaewpark         ###   ########.fr       */
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
        if (ret == std::end(first))
            throw (std::out_of_range("\e[91mNot found\e[0m : "));
        return ret;
    } catch(std::exception &e) {
        std::cout << e.what();
    }
    return ret;
};

#endif