#include "../includes/Span.hpp"
#include <stdexcept>
#include <sstream>
#include <climits>

Span::Span(){};

Span::Span(unsigned int n): _maxSize(n), _shortestSpan(LONG_MAX), _hasSpan(false)
{
};

Span::Span(const Span &other): _maxSize(other._maxSize), _data(other._data),
								_shortestSpan(other._shortestSpan), _hasSpan(other._hasSpan)
{
};

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_data = other._data;
		_shortestSpan = other._shortestSpan;
		_hasSpan = other._hasSpan;
	}
	return (*this);
};

Span::~Span(){};

void	Span::addNumber(int num)
{
	if (_data.size() >= _maxSize)
	{
		std::stringstream ss;
		ss << "span: failed to add num " << num << ", span is full";
		std::string err = ss.str();
		throw std::overflow_error(err.c_str());
	}
	std::multiset<int>::iterator it = _data.insert(num);
	if (_data.size() >= 2)
	{
		_hasSpan = true;
		if (it != _data.begin())
		{
			std::multiset<int>::iterator prev = it;
			prev--;
			long diff = static_cast<long>(*it) - static_cast<long>(*prev);
			if (diff < _shortestSpan)
				_shortestSpan = diff;
		}
		std::multiset<int>::iterator next = it;
		next++;
		if (next != _data.end())
		{
			long diff = static_cast<long>(*next) - static_cast<long>(*it);
			if (diff < _shortestSpan)
				_shortestSpan = diff;
		}
	}
}

long	Span::shortestSpan()
{
	if (!_hasSpan)
		throw NoSpanException();
	return (_shortestSpan);
};

long	Span::longestSpan()
{
	if (!_hasSpan)
		throw NoSpanException();
	std::multiset<int>::iterator minIt = _data.begin();
	std::multiset<int>::iterator maxIt = --_data.end();
	return (static_cast<long>(*maxIt) - static_cast<long>(*minIt));
};

const char* Span::NoSpanException::what() const throw()
{
	return ("element count ineligible to form a span.");
};