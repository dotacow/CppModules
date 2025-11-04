#pragma once
#include <stack>
#include <string>

enum e_tokenType
{
	NUMBER,
	OPERATOR
};

struct t_token
{
	private:
		e_tokenType	type;
		union
		{
			long long number;
			char op;
		}			value;
	public:
		void setToken(char c);
		e_tokenType getType() const;
		long long getNum() const;
		char getOp() const;
};

class RPN
{
	private:
		std::stack<t_token> _data;
		RPN();
	public:
		RPN(const std::string expr);
		RPN(const RPN& other);
		RPN& operator=(const RPN &other);
		~RPN();
};