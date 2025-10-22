#pragma once
#include <set>
#include <stdexcept>

class Span
{
	private:
		unsigned int		_maxSize;
		std::multiset<int>	_data;
		long				_shortestSpan;
		bool				_hasSpan;
		Span();
	public:
		//canonical form
		Span(unsigned int n);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		//member methods
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
		//exceptions
		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};