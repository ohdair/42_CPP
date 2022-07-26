#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T *array, int array_length, void f(T const &ref))
{
    for (int i = 0; i < array_length; i++)
        f(array[i]);
}
#endif