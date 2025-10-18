
#pragma once

#include <iostream>

template <typename T>
struct iterator
{
	static void iter(T *array, const int length, void (*f)(T &))
	{
		for (int i = 0; i < length; i++)
		{
			f(array[i]);
		}
	}
	static void iter(const T *array, const int length, void (*f)(const T &))
	{
		for (int i = 0; i < length; i++)
		{
			f(array[i]);
		}
	}

	static void printType(const T &elem)
	{
		std::cout << elem << std::endl;
	}

	static void multiplyByTwo(T &elem)
	{
		elem *= 2;
	}
};