#pragma once
#include <iostream>
#include <cmath>

class Point {
private:
	double x_;
	double y_;

public:
	Point() : x_{ 0.0 }, y_{ 0.0 } {};

	Point(double x, double y) : x_{ x }, y_{ y } {};

	Point(const Point& point) : x_{ point.x_ }, y_{ point.y_ } {};

	Point(Point&&);

	Point& operator=(const Point&);

	Point& operator=(Point&&);

	Point operator+(const Point& point) const { return Point(x_ + point.x_, y_ + point.y_); };

	Point operator-(const Point& point) const { return Point(x_ - point.x_, y_ - point.y_); };
	
	Point operator*(double scalar) const { return Point(x_ * scalar, y_ * scalar); };

	Point operator/(double) const;

	Point& operator+=(const Point&);

	Point& operator-=(const Point&);

	Point& operator*=(double);

	Point& operator/=(double);

	bool operator==(const Point&) const;

	bool operator!=(const Point&) const;

	double x() const { return x_; };

	double y() const { return y_; };

	void setX(double x) { x_ =  x; };

	void setY(double y) { y_ = y; };

	double distance(const Point&) const;

};

// Stream insertion operator
std::ostream& operator<<(std::ostream&, const Point&);
std::istream& operator>>(std::istream&, Point&);
