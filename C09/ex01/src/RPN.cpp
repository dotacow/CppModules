#include "../includes/RPN.hpp"
#include <iostream>

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN&	RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

RPN::RPN(const std::string expr)
{
	int	pos = 0;
	ParseExpr(expr, pos);
	if (_data.size() != 1)
		throw std::runtime_error("Error: Invalid RPN expression");
	std::cout << _data.top() << "\n";
}

RPN::~RPN()
{
}

void	RPN::ParseExpr(const std::string &expr, int &pos)
{
	if (pos >= static_cast<int>(expr.length()))
		return;
	while(std::isspace(expr[pos]))
		pos++;
	if (pos >= static_cast<int>(expr.length()))
		return;
	if (IsNum(expr[pos]))
	{
		_data.push(expr[pos] - '0');
		pos++;
		ParseExpr(expr, pos);
	}
	else if(IsOp(expr[pos]))
	{
		ApplyOp(expr[pos]);
		pos++;
		ParseExpr(expr, pos);
	}
	else
	{
		std::cerr << "Unexpected token: " << expr[pos] << "\n";
		return;
	}
}

bool	RPN::IsNum(char c) const { return (c >= '0' && c <= '9');}

bool	RPN::IsOp(char c) const { return (c == '+' || c == '-'
									|| c == '*' || c == '/'); }

void	RPN::ApplyOp(char op)
{
	if (_data.size() < 2)
		throw RPN::RPNInsufficientOperands();
	long long	right = _data.top(); _data.pop();
	long long	left = _data.top(); _data.pop();
	long long	res;
	switch (op)
	{
		case '+':
			res = left + right;
			break;
		case '-':
			res = left - right;
			break;
		case '*':
			res = left * right;
			break;
		case '/':
			if (right == 0)
				throw RPN::RPNDivByZero();
			res = left / right;
			break;
		default:
			throw std::runtime_error("Error: Unknown operator");
	}
	_data.push(res);
}

const char* RPN::RPNDivByZero::what() const throw()
{
	return "Error: Division by zero";
}

const char* RPN::RPNInsufficientOperands::what() const throw()
{
	return "Error: Insufficient operands for operation";
}