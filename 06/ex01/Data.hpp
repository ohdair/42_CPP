/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:18:23 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/25 13:38:40 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
    public:
        Data();
        Data(std::string input);
        Data(const Data& data);
        ~Data();
        Data& operator=(const Data& data);

        std::string getData() const;
    private:
        std::string data;
};

#endif