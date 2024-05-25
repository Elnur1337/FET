#include "PostfixCalc.h"

PostfixCalc::PostfixCalc(const PostfixCalc& second) : operands_{ second.operands_ } {};

PostfixCalc::PostfixCalc(PostfixCalc&& second) : operands_{ std::move(second.operands_) } {};

PostfixCalc& PostfixCalc::operator=(const PostfixCalc& second) {
	operands_ = second.operands_;
	return *this;
}

PostfixCalc& PostfixCalc::operator=(PostfixCalc&& second) {
	operands_ = std::move(second.operands_);
	return *this;
}

PostfixCalc& PostfixCalc::add(std::string line) {
	std::string value;
	size_t cPos;
	do {
		cPos = line.find(' ');
		value = line.substr(0, cPos);
		std::cout << value << std::endl;
		if (value.length() == 1) {
			if (value == "+") {
				if (operands_.size() < 2) {
					throw std::invalid_argument("Invalid input!");
				}
				const int first{ operands_.top() };
				operands_.pop();
				const int second{ operands_.top() };
				operands_.pop();
				operands_.push(second + first);
			}
			else if (value == "-") {
				if (operands_.size() < 2) {
					throw std::invalid_argument("Invalid input!");
				}
				const int first{ operands_.top() };
				operands_.pop();
				const int second{ operands_.top() };
				operands_.pop();
				operands_.push(second - first);
			} 
			else if (value == "*") {
				if (operands_.size() < 2) {
					throw std::invalid_argument("Invalid input!");
				}
				const int first{ operands_.top() };
				operands_.pop();
				const int second{ operands_.top() };
				operands_.pop();
				operands_.push(second * first);
			}
			else if (value == "/") {
				if (operands_.size() < 2) {
					throw std::invalid_argument("Invalid input!");
				}
				const int first{ operands_.top() };
				if (first == 0) {
					throw std::invalid_argument("Division by zero!");
				}
				operands_.pop();
				const int second{ operands_.top() };
				operands_.pop();
				operands_.push(second / first);
			}
			else {
				try
				{
					const int number{ std::stoi(value) };
					operands_.push(number);
				}
				catch (const std::exception& e)
				{
					throw std::invalid_argument("Invalid input!");
				}
			}
		}
		else {
			try
			{
				const int number{ std::stoi(value) };
				operands_.push(number);
			}
			catch (const std::exception& e)
			{
				throw std::invalid_argument("Invalid input!");
			}
		}
		line = line.substr(cPos + 1, line.length());
	} while (cPos != std::string::npos);
	return *this;
}

PostfixCalc& PostfixCalc::add(int number) {
	operands_.push(number);
	return *this;
}

std::istream& operator>>(std::istream& inputStream, PostfixCalc& calc) {
	std::string line;
	std::getline(inputStream >> std::ws, line);
	calc.add(line);
	return inputStream;
}