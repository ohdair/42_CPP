/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:30:35 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/29 14:30:17 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
    public:
        Array();
        Array(T n);
        Array(const Array& array);
        virtual ~Array();
        Array& operator=(const Array& array);

        unsigned int size(void) const;
        T& operator[](int i);
        T *getArray(void) const;
    private:
        T *t;
        unsigned int n;
};

template<typename T>
Array<T>::Array(void) : n(0)
{
    this->t = new T[1];
    this->t[0] = 0;
    std::cout << "New array has been constructed\n" << *this << std::endl;
}

template<typename T>
Array<T>::Array(T n) : n(n)
{
    this->t = new T[n];
    std::cout << "New array has been constructed\n" << *this << std::endl;
}

template<typename T>
Array<T>::Array(const Array& array) : n(array.n)
{
    this->t = new T[n];
    for (unsigned int i = 0; i < n; i++)
        this->t[i] = array.t[i];
    std::cout << "New array has been copied\n" << *this << std::endl;
}

template<typename T>
Array<T>::~Array(void)
{
    std::cout << "Array has been constructed" << std::endl;
    delete [] this->t;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& array)
{
    delete [] this->t;
    this->n = array.n;
    this->t = new T[n];
    for (unsigned int i = 0; i < n; i++)
        this->t[i] = array.t[i];
    return *this;
    std::cout << "New array has been copied\n" << *this << std::endl;
}

template<typename T>
unsigned int Array<T>::size(void) const
{
    return this->n;
}

template<typename T>
T& Array<T>::operator[](int i)
{
    if (i < 0 || i >= static_cast<int>(this->n))
        throw (std::out_of_range("\e[91mOut of range\e[0m"));
    else
        std::cout << "T[" << i << "] : " << *(this->t + i) << std::endl;
    return (*(t + i));
}

template<typename T>
T * Array<T>::getArray(void) const
{
    return this->t;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, Array<T> const &ref)
{
    for (unsigned int i = 0; i < ref.size(); i++)
        std::cout << " T[" << i << "] : " << *(ref.getArray() + i) << std::endl;
    return (os);
}

#endif