/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:41:57 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/23 19:47:26 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(void) {}
Conversion::Conversion(const Conversion& conversion) : origin(conversion.origin) {}
Conversion::~Conversion(void) {}
Conversion& Conversion::operator=(const Conversion& conversion)
{
    this->origin = conversion.origin;
    return *this;
}

