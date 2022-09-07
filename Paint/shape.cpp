#include "shape.h"

Point& Point::operator+(const Point& other) {
	auto suma = Point(x + other.x, y + other.y);
	return suma;
}
Point& Point::operator-(const Point& other) {
	auto resta = Point(p1.x + p2.x, p1.y + p2.y);
	return resta;
}
