#include "../includes/VecSpan.hpp"
#include <sstream>
#include <climits>
#include <algorithm>

VecSpan::VecSpan(): _maxSize(0), _shortestSpan(LONG_MAX), _hasSpan(false), _sorted(false)
{}

VecSpan::VecSpan(unsigned int n): _maxSize(n), _shortestSpan(LONG_MAX), _hasSpan(false), _sorted(false)
{}

VecSpan::VecSpan(const VecSpan &other)
{
	*this = other;
}

VecSpan& VecSpan::operator=(const VecSpan &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_data = other._data;
		_shortestSpan = other._shortestSpan;
		_hasSpan = other._hasSpan;
		_sorted = other._sorted;
	}
	return *this;
}

VecSpan::~VecSpan()
{}

void VecSpan::addNumber(int number)
{
	if (_data.size() >= _maxSize)
	{
		std::stringstream ss;
		ss << "vecspan: failed to add num " << number << ", span is full";
		throw std::overflow_error(ss.str().c_str());
	}
	_data.push_back(number);
	if (_data.size() >= 2)
		_hasSpan = true;
	_sorted = false;
}

long VecSpan::shortestSpan()
{
	if (!_hasSpan)
		throw NoSpanException();
	if (!_sorted)
	{
		std::sort(_data.begin(), _data.end());
		_sorted = true;
		_shortestSpan = LONG_MAX;
		for (std::vector<int>::size_type i = 1; i < _data.size(); i++)
		{
			long diff = static_cast<long>(_data[i]) - static_cast<long>(_data[i-1]);
			if (diff < _shortestSpan)
				_shortestSpan = diff;
		}
	}
	return _shortestSpan;
}

long VecSpan::longestSpan()
{
	if (!_hasSpan)
		throw NoSpanException();
	if (!_sorted)
		std::sort(_data.begin(), _data.end());
	return static_cast<long>(_data.back()) - static_cast<long>(_data.front());
}

const char* VecSpan::NoSpanException::what() const throw()
{
	return "element count ineligible to form a span.";
}
