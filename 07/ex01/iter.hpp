/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:27:36 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/27 11:37:38 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T *array, int array_length, void f(T const &ref))
{
    for (int i = 0; i < array_length; i++)
        f(array[i]);
}

template<typename T>
void displayElements(T const &ref)
{
    std::cout << ref << std::endl;
}

#endif