
#pragma once

template <typename T>
struct whatever
{
	static void swap(T &a, T &b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	static const T &min(const T &a, const T &b)
	{
		return (a < b ? a : b);
	}

	static const T &max(const T &a, const T &b)
	{
		return (a > b ? a : b);
	}
};