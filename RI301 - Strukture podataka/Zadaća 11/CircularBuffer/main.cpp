#include <iostream>
#include "CircularBuffer.hpp"

int main() {

	CircularBuffer<int> buffer(5);
	buffer.push(1).push(2).push(3);
	std::cout << buffer << std::endl;
	buffer.push(1).push(2).push(3);
	std::cout << buffer << std::endl;

	buffer.pop();
	std::cout << buffer << std::endl;
	buffer.pop();
	std::cout << buffer << std::endl;
	buffer.pop();
	std::cout << buffer << std::endl;
	buffer.pop();
	std::cout << buffer << std::endl;

	buffer.push(1).push(2).push(3);
	std::cout << buffer << std::endl;
	buffer.push(1).push(2).push(3);
	std::cout << buffer << std::endl;

	buffer.pop();
	std::cout << buffer << std::endl;
	buffer.pop();
	std::cout << buffer << std::endl;
	buffer.pop();
	std::cout << buffer << std::endl;
	buffer.pop();
	std::cout << buffer << std::endl;
	buffer.pop();
	std::cout << buffer << std::endl;
	buffer.push(1).push(2).push(3);
	std::cout << buffer << std::endl;
	buffer.push(1).push(2).push(3);
	std::cout << buffer << std::endl;
	buffer.pop();
	std::cout << buffer << std::endl;
	buffer.pop();
	std::cout << buffer << std::endl;
	buffer.pop();
	std::cout << buffer << std::endl;
	buffer.pop();
	std::cout << buffer << std::endl;
	buffer.resize(10);
	buffer.push(22);
	//  buffer.push(30).push(5).push(7).push(9).push(10).push(-2);
	std::cout << buffer << std::endl;

	return 0;
}
