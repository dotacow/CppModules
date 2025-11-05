#pragma once
#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<long long>	_data;
		//OOP was a mistake.
		RPN();
		RPN(const RPN& other);
		RPN&	operator=(const RPN &other);
		//Methods
		void	ParseExpr(const std::string &expr, int &pos);
		void	ApplyOp(char op);
		bool	IsOp(char c) const;
		bool	IsNum(char c) const;
	public:
		RPN(const std::string expr);
		~RPN();
	//Exceptions
	class RPNDivByZero : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class RPNInsufficientOperands : public std::exception
	{
		public:
			const char* what() const throw();
	};
};