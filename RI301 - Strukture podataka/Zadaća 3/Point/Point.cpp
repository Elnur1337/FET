#include "Point.hpp"

Point::Point(Point&& point) : x_{ std::move(point.x_) }, y_{ std::move(point.y_) } {
	point.x_ = 0.0;
	point.y_ = 0.0;
	return;
}

Point& Point::operator=(const Point& point) {
	x_ = point.x_;
	y_ = point.y_;
	return *this;
}

Point& Point::operator=(Point&& point) {
	x_ = std::move(point.x_);
	y_ = std::move(point.y_);
	point.x_ = 0.0;
	point.y_ = 0.0;
	return *this;
}

Point Point::operator/(double scalar) const {
	if (scalar == 0.0) {
		throw std::invalid_argument("Division by zero!");
	}
	return Point(x_ / scalar, y_ / scalar);
}

Point& Point::operator+=(const Point& point) {
	x_ += point.x_;
	y_ += point.y_;
	return *this;
}

Point& Point::operator-=(const Point& point) {
	x_ -= point.x_;
	y_ -= point.y_;
	return *this;
}

Point& Point::operator*=(double scalar) {
	x_ *= scalar;
	y_ *= scalar;
	return *this;
}

Point& Point::operator/=(double scalar) {
	if (scalar == 0.0) {
		throw std::invalid_argument("Division by zero!");
	}
	x_ /= scalar;
	y_ /= scalar;
	return *this;
}

bool Point::operator==(const Point& point) const {
	if (x_ == point.x_ && y_ == point.y_) {
		return true;
	}
	return false;
}

bool Point::operator!=(const Point& point) const {
	return !((*this) == point);
}

double Point::distance(const Point& point) const {
	return sqrt(pow(point.x_ - x_, 2) + pow(point.y_ - y_, 2));
}

std::ostream& operator<<(std::ostream& outputStream, const Point& point) {
	bool isXInt = false;
	bool isYInt = false;
	if ((point.x() / (int)point.x()) - 1 == 0.0) {
		isXInt = true;
	}
	if ((point.y() / (int)point.y()) - 1 == 0.0) {
		isYInt = true;
	}
	outputStream << "Point(x=" << (isXInt ? (int)point.x() : point.x()) << ", y=" << (isYInt ? (int)point.y() : point.y()) << ")\n";
	return outputStream;
}

std::istream& operator>>(std::istream& inputStream, Point& point) {
	double inputValue;
	inputStream >> inputValue;
	point.setX(inputValue);
	inputStream >> inputValue;
	point.setY(inputValue);
	return inputStream;
}