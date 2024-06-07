#include <iostream>
#include <vector>
#include <iomanip>

bool isValid(const std::vector<std::vector<short>>&, unsigned short, unsigned short);
bool findPath(std::vector<std::vector<short>>&, unsigned short, unsigned short);

int main() {
	std::vector<std::vector<short>> board(8, std::vector<short>(8, -1));
	board[0][0] = 0;

	if (findPath(board, 0, 0)) {
		for (short i{ 0 }; i < board.size(); ++i) {
			for (short j{ 0 }; j < board[0].size(); ++j) {
				std::cout << std::setw(2) << board[i][j] << " ";
			}
			std::cout << std::endl;
		}
		return 0;
	}
	std::cout << "Path not found!\n";
	return 0;
}

bool isValid(const std::vector<std::vector<short>>& board, unsigned short currX, unsigned short currY) {
	if (currX >= 0 && currX < board.size() && currY >= 0 && currY < board[0].size() && board[currX][currY] == (short)-1) {
		return true;
	}
	return false;
}

bool findPath(std::vector<std::vector<short>>& board, unsigned short currX, unsigned short currY) {
	const static std::vector<short> moveX{ 2, 1, -1, -2, -2, -1, 1, 2 };
	const static std::vector<short> moveY{ 1, 2, 2, 1, -1, -2, -2, -1 };
	static short moveCounter{ 0 };

	if (moveCounter == 63) {
		return true;
	}
	for (short i{ 0 }; i < moveX.size(); ++i) {
		if (isValid(board, currX + moveX[i], currY + moveY[i])) {
			board[currX + moveX[i]][currY + moveY[i]] = ++moveCounter;
			if (findPath(board, currX + moveX[i], currY + moveY[i])) {
				return true;
			}
			else {
				board[currX + moveX[i]][currY + moveY[i]] = (short)-1;
				--moveCounter;
			}
		}
	}
	return false;
}