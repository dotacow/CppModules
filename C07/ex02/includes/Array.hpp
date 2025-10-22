#pragma once
#include <stdexcept>

template<typename T> class Array
{
	private:
		T*				_array;
		unsigned int	_size;
	public:
		Array()
		{
			_array = new T[0]();
			_size = 0;
		}

		Array(unsigned int n)
		{
			_array = new T[n]();
			_size = n;
		}

		Array(const Array& other)
		{
			_size = other._size;
			_array = new T[_size];
			for(unsigned int i = 0; i < _size; i++)
				_array[i] = other[i];
		}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete [] _array;
				_size = other._size;
				_array = new T[_size];
				for(unsigned int i = 0; i < _size; i++)
					_array[i] = other[i];
			}
			return (*this);
		}

		~Array()
		{
			delete [] _array;
		}

		unsigned int size() const
		{
			return (_size);
		}

		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::out_of_range("index out of range");
			return (_array[index]);
		}
		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::out_of_range("index out of range");
			return (_array[index]);
		}
};

