#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename T_func>
void iter(T* array, size_t array_length, T_func func)
{
	for (size_t i = 0; i < array_length; i++)
	{
		func(array[i]);
	}
}

#endif
