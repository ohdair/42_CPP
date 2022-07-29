/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:51:52 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/29 14:45:36 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <iostream>
# include <stack>
# include <vector>
# include <iterator>
# include <iomanip>
# include <cmath>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        MutantStack();
        MutantStack(const MutantStack &ref);
        ~MutantStack();
        MutantStack& operator=(const MutantStack &ref);

        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
    private:
};

template<typename T>
MutantStack<T>::MutantStack(void) { std::cout << "Stack has been constructed\n"; }
template<typename T>
MutantStack<T>::MutantStack(const MutantStack &ref)
{
    std::cout << "Stack has been copied\n";
    this = ref;
}
template<typename T>
MutantStack<T>::~MutantStack(void) { std::cout << "Stack has been destroyed\n"; }
template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &ref)
{
    if (this != &ref)
        this = std::stack<T>::operator=(ref);
    return *this;
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin(void) { return MutantStack<T>::iterator(this->c.begin()); }

template<typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin(void) const { return this->c.begin(); }

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end(void) { return MutantStack<T>::iterator(this->c.end()); }

template<typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end(void) const { return this->c.end(); }

template<typename T>
std::ostream &operator<<(std::ostream &os, MutantStack<T> &st){
	os << "┌─────┐" << std::endl;
	for(typename std::stack<T>::container_type::iterator i = st.end(); i-- != st.begin(); ){
	    os << std::setfill(' ') << ((std::ceil(std::log10l(*i)) < 3) ? std::setw(4) : std::setw(5))
        << *i << std::endl;
	}
	os << "└─────┘" << std::endl;
    return os;
}

#endif