/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:10:52 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/10 19:17:44 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>
# include <algorithm>

class Harl
{
    public:
        Harl();
        void complain(std::string level);
        ~Harl();
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif