#include <iostream>
#include "shape.h"


Point& Point::operator+(const Point& other) {
	auto suma = Point(x + other.x, y + other.y);
	return suma;
}

Point& Point::operator-(const Point& other) {
	auto resta = Point(x + other.x, y + other.y);
	return resta;
}

Point& Point::operator=(vector<int> other) {
	x = other[0];
	y = other[1];

	return *this;
}
