#include <iostream>
#include <vector>

bool isValid(const std::vector<std::vector<int>>&, size_t, size_t);
bool findPath(const std::vector<std::vector<int>>&, std::vector<std::vector<int>>&, size_t, size_t);

int main() {
	size_t rows, cols;
	std::cin >> rows >> cols;

	std::vector<std::vector<int>> maze(rows, std::vector<int>(cols));
	std::vector<std::vector<int>> path(rows, std::vector<int>(cols, 0));

	for (size_t i{ 0 }; i < rows; ++i) {
		for (size_t j{ 0 }; j < cols; ++j) {
			std::cin >> maze[i][j];
		}
	}
	if (findPath(maze, path, 0, 0)) {
		for (size_t i{ 0 }; i < rows; ++i) {
			for (size_t j{ 0 }; j < cols; ++j) {
				std::cout << path[i][j] << " ";
			}
			std::cout << std::endl;
		}
		return 0;
	}
	std::cout << "Path not found!\n";
	return 0;
}

bool isValid(const std::vector<std::vector<int>>& maze, size_t currX, size_t currY) {
	if (currX >= 0 && currX < maze.size() && currY >= 0 && currY < maze[0].size() && maze[currX][currY] != 1) {
		return true;
	}
	return false;
}

bool findPath(const std::vector<std::vector<int>>& maze, std::vector<std::vector<int>>& path, size_t currX, size_t currY) {
	if (currX == maze.size() - 1 && currY == maze[0].size() - 1 && maze[currX][currY] != 1) {
		path[currX][currY] = 1;
		return true;
	}
	if (isValid(maze, currX, currY)) {
		path[currX][currY] = 1;

		if (findPath(maze, path, currX, currY + 1)) {
			return true;
		}
		if (findPath(maze, path, currX + 1, currY)) {
			return true;
		}
		path[currX][currY] = 0;
		return false;
	}
	return false;
}