#pragma once
#include <vector>
#include <stdexcept>

class VecSpan
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_data;
		long				_shortestSpan;
		bool				_hasSpan;
		bool				_sorted;
		VecSpan();
	public:
		// canonical form
		VecSpan(unsigned int n);
		VecSpan(const VecSpan &other);
		VecSpan& operator=(const VecSpan &other);
		~VecSpan();
		// member methods
		void				addNumber(int number);
		long				shortestSpan();
		long				longestSpan();
		template<typename iterator>
		void				addRange(iterator begin, iterator end)
		{
			while (begin != end)
			{
				try
				{
					addNumber(*begin);
				}
				catch (std::overflow_error &e)
				{
					throw;
				}
				++begin;
			}
		};

		// exceptions
		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
