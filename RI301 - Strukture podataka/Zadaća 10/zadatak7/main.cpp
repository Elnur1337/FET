#include <iostream>
#include <string>
#include <map>
#include "Stack.h"

int main() {
	Stack<unsigned int> openBracketsNumber;
	std::map<char, unsigned int> bracketNumberValue;
	bracketNumberValue['<'] = 1;
	bracketNumberValue['>'] = 1;
	bracketNumberValue['('] = 2;
	bracketNumberValue[')'] = 2;
	bracketNumberValue['['] = 3;
	bracketNumberValue[']'] = 3;
	bracketNumberValue['{'] = 4;
	bracketNumberValue['}'] = 4;
	std::string line;
	bool isLineCorrect;
	char currentBracket;
	unsigned int currentBracketNumber;
	do {
		isLineCorrect = true;
		openBracketsNumber.clear();
		std::getline(std::cin >> std::ws, line);
		for (size_t i = 0; i < line.length(); ++i) {
			currentBracket = line[i];
			if (currentBracket == '{') {
				currentBracketNumber = bracketNumberValue[currentBracket];
				if (!openBracketsNumber.empty() && (openBracketsNumber.top() < currentBracketNumber)) {
					isLineCorrect = false;
					break;
				}
				openBracketsNumber.push(currentBracketNumber);
			}
			else if (currentBracket == '[') {
				currentBracketNumber = bracketNumberValue[currentBracket];
				if (!openBracketsNumber.empty() && (openBracketsNumber.top() < currentBracketNumber)) {
					isLineCorrect = false;
					break;
				}
				openBracketsNumber.push(currentBracketNumber);
			}
			else if (currentBracket == '(') {
				currentBracketNumber = bracketNumberValue[currentBracket];
				if (!openBracketsNumber.empty() && (openBracketsNumber.top() < currentBracketNumber)) {
					isLineCorrect = false;
					break;
				}
				openBracketsNumber.push(currentBracketNumber);
			}
			else if (currentBracket == '<') {
				currentBracketNumber = bracketNumberValue[currentBracket];
				if (!openBracketsNumber.empty() && (openBracketsNumber.top() < currentBracketNumber)) {
					isLineCorrect = false;
					break;
				}
				openBracketsNumber.push(currentBracketNumber);
			}
			else if (currentBracket == '}') {
				currentBracketNumber = bracketNumberValue[currentBracket];
				if (openBracketsNumber.empty() || (openBracketsNumber.top() < currentBracketNumber)) {
					isLineCorrect = false;
					break;
				}
				openBracketsNumber.pop();
			}
			else if (currentBracket == ']') {
				currentBracketNumber = bracketNumberValue[currentBracket];
				if (openBracketsNumber.empty() || (openBracketsNumber.top() < currentBracketNumber) || (openBracketsNumber.top() > currentBracketNumber)) {
					isLineCorrect = false;
					break;
				}
				openBracketsNumber.pop();
			}
			else if (currentBracket == ')') {
				currentBracketNumber = bracketNumberValue[currentBracket];
				if (openBracketsNumber.empty() || (openBracketsNumber.top() < currentBracketNumber) || (openBracketsNumber.top() > currentBracketNumber)) {
					isLineCorrect = false;
					break;
				}
				openBracketsNumber.pop();
			}
			else if (currentBracket == '>') {
				currentBracketNumber = bracketNumberValue[currentBracket];
				if (openBracketsNumber.empty() || (openBracketsNumber.top() < currentBracketNumber) || (openBracketsNumber.top() > currentBracketNumber)) {
					isLineCorrect = false;
					break;
				}
				openBracketsNumber.pop();
			}
			else {
				isLineCorrect = false;
				break;
			}
		}
		if (isLineCorrect && openBracketsNumber.empty()) {
			std::cout << "dobar" << std::endl;
		}
		else {
			std::cout << "pogresan" << std::endl;
		}
	} while (std::cin);
	return 0;
}