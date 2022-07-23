/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:41:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/23 19:44:38 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>

class Conversion
{
    public:
        Conversion();
        Conversion(const Conversion& conversion);
        ~Conversion();
        Conversion& operator=(const Conversion& conversion);
    private:
        std::string origin;
};

#endif