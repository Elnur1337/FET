#pragma once
#include <iostream>
#include <string>
#include <stack>

class PostfixCalc {
private:
	std::stack<int> operands_;

	friend std::istream& operator>>(std::istream&, PostfixCalc&);
public:
	PostfixCalc() = default;
	PostfixCalc(const PostfixCalc&);
	PostfixCalc(PostfixCalc&&);

	PostfixCalc& operator=(const PostfixCalc&);
	PostfixCalc& operator=(PostfixCalc&&);

	PostfixCalc& add(std::string);
	PostfixCalc& add(int);

	inline int result() const { return operands_.top(); };
};