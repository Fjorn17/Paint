#include <iostream>
#include "shape.h"


Point& Point::operator+(const Point& other) {
	auto suma = new Point(x + other.x, y + other.y);
	return *suma;
}

Point& Point::operator-(const Point& other) {
	auto resta = new Point(x + other.x, y + other.y);
	return *resta;
}

Point& Point::operator=(vector<int> other) {
	x = other[0];
	y = other[1];

	return *this;
}
