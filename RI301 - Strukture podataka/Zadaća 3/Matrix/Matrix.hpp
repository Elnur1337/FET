#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>

class Matrix {

private:
	std::vector<std::vector<T>> matrix_;

public:
	Matrix() = default;

	Matrix(size_t rows, size_t cols) {
		for (unsigned int i = 0; i < rows; ++i) {
			matrix_.push_back(std::vector<T>(cols));
		}
		return;
	}

	Matrix(const Matrix& other) {
		std::pair<size_t, size_t> dimensions = other.size();
		for (size_t i = 0; i < dimensions.first; ++i) {
			matrix_.push_back(std::vector<T>(dimensions.second));
			std::copy(other[i].begin(), other[i].end(), matrix_[i].begin());
		}
		return;
	}

	Matrix(Matrix&& other) : matrix_{ std::move(other.matrix_) } {};

	Matrix& operator=(const Matrix& other) {
		matrix_.clear();
		std::pair<size_t, size_t> dimensions = other.size();
		for (size_t i = 0; i < dimensions.first; ++i) {
			matrix_.push_back(std::vector<T>(dimensions.second));
		}
		for (size_t i = 0; i < dimensions.first; ++i) {
			std::copy(other[i].begin(), other[i].end(), matrix_[i].begin());
		}
		return *this;
	}
	Matrix& operator=(Matrix&& other) {
		matrix_ = std::move(other.matrix_);
		return *this;
	};

	T& at(size_t row, size_t column) {
		const std::pair<size_t, size_t> matrixDimensions = this->size();
		if (row > matrixDimensions.first || column > matrixDimensions.second) {
			throw std::out_of_range("Indexes out of range!");
		}
		return matrix_.at(row).at(column);
	}
	const T& at(size_t row, size_t column) const {
		const std::pair<size_t, size_t> matrixDimensions = this->size();
		if (row > matrixDimensions.first || column > matrixDimensions.second) {
			throw std::out_of_range("Indexes out of range!");
		}
		return matrix_.at(row).at(column);
	}

	std::vector<T>& operator[](size_t row) { return matrix_[row]; };
	const std::vector<T>& operator[](size_t row) const { return matrix_[row]; };

	bool operator==(const Matrix& other) const {
		if (this->size() == other.size()) {
			for (unsigned int i = 0; i < this->size().first; ++i) {
				if ((*this)[i] != other[i]) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

	bool operator!=(const Matrix& other) const {
		return !(this->operator==(other));
	}

	Matrix operator+(const Matrix& other) const {
		if (this->size() != other.size()) {
			throw std::invalid_argument("Matrices don't have same dimensions!");
		}
		const std::pair<size_t, size_t> dimensions = other.size();
		Matrix returnValue(other);
		for (size_t i = 0; i < dimensions.first; ++i) {
			for (size_t j = 0; j < dimensions.second; ++j) {
				returnValue.at(i, j) += this->at(i, j);
			}
		}
		return returnValue;
	}
	Matrix operator*(const Matrix& other) const {
		const std::pair<size_t, size_t> lhsDimensions = this->size();
		const std::pair<size_t, size_t> rhsDimensions = other.size();
		if (lhsDimensions.second != rhsDimensions.first) {
			throw std::invalid_argument("Matrices are not chained!");
		}
		Matrix returnValue(lhsDimensions.first, rhsDimensions.second);
		T sum = 0;
		for (size_t i = 0; i < lhsDimensions.first; ++i) {
			for (size_t j = 0; j < rhsDimensions.second; ++j) {
				sum = 0;
				for (size_t k = 0; k < lhsDimensions.second; ++k) {
					sum += (this->at(i, k) * other.at(k, j));
				}
				returnValue.at(i, j) = sum;
			}
		}
		return returnValue;
	}

	Matrix operator*(T factor) const {
		Matrix returnValue(*this);
		const std::pair<size_t, size_t> matrixDimensions = this->size();
		for (size_t i = 0; i < matrixDimensions.first; ++i) {
			for (size_t j = 0; j < matrixDimensions.second; ++j) {
				returnValue.at(i, j) *= factor;
			}
		}
		return returnValue;
	}

	std::vector<T> mainDiagonal() const {
		std::vector<T> mDiagonal;
		const std::pair<size_t, size_t> matrixDimensions = this->size();
		for (size_t i = 0; i < matrixDimensions.first; ++i) {
			try
			{
				mDiagonal.push_back(this->at(i, i));
			}
			catch (const std::exception& e)
			{
				return mDiagonal;
			}
		}
		return mDiagonal;
	}

	std::vector<T> secondaryDiagonal() const {
		std::vector<T> sDiagonal;
		const std::pair<size_t, size_t> matrixDimensions = this->size();
		for (size_t i = 0; i < matrixDimensions.first; ++i) {
			try
			{
				sDiagonal.push_back(this->at(i, matrixDimensions.first - 1 - i));
			}
			catch (const std::exception& e)
			{
				return sDiagonal;
			}
		}
		return sDiagonal;
	}

	std::pair<size_t, size_t> size() const {
		if (matrix_.size() == 0) {
			return std::pair<size_t, size_t>(0, 0);
		}
		return std::pair<size_t, size_t>(matrix_.size(), matrix_[0].size());
	}

	Matrix& push_back(const std::vector<T>& row) {
		if (this->size().first != 0) {
			if (row.size() != this->size().second) {
				throw std::invalid_argument("Invalid number of elements in vector!");
			}
		}
		matrix_.push_back(row);
		return *this;
	}

	Matrix& push_back(const std::initializer_list<T>& row) {
		if (this->size().first != 0) {
			if (row.size() != this->size().second) {
				throw std::invalid_argument("Invalid number of elements in vector!");
			}
		}
		matrix_.push_back(std::vector<T>(row));
		return *this;
	}

	Matrix& expand(const std::initializer_list<T>& row) {
		if (row.size() != this->size().second) {
			throw std::invalid_argument("Invalid number of elements in vector!");
		}
		for (size_t i = 0; i < row.size(); ++i) {
			matrix_[i].push_back(row.begin()[i]);
		}
		return *this;
	}

	Matrix& expand(const std::vector<T>& row) {
		if (row.size() != this->size().second) {
			throw std::invalid_argument("Invalid number of elements in vector!");
		}
		for (size_t i = 0; i < row.size(); ++i) {
			matrix_[i].push_back(row[i]);
		}
		return *this;
	}

	template <typename U>
	Matrix& expand(U&& element) {
		const U tempElement = std::move(element);
		for (size_t i = 0; i < this->size().first; ++i) {
			matrix_[i].push_back(tempElement);
		}
		return *this;
	}

};
