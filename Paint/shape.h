#ifndef SHAPE_H
#define SHAPE_H 

#include <string>
#include <iostream>

using namespace std;


struct Color
{
	static constexpr Color red() { return Color(255, 0, 0); }
	static constexpr Color green() { return Color(0, 255, 0); }
	static constexpr Color blue() { return Color(0, 0, 255); }
	static constexpr Color black() { return Color(0, 0, 0); }
	static constexpr Color white() { return Color(255, 255, 255); }

	constexpr Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
		: r(r), g(g), b(b), a(a)
	{}

	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};


class Point {
private:
	int x;
	int y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }

	friend Point& operator+(const Point& p1, const Point& p2);
	friend Point& operator-(const Point& p1, const Point& p2);
};
Point& operator+(const Point& p1, const Point& p2) {
	auto suma = Point(p1.x + p2.x, p1.y + p2.y);
	return suma;
}
Point& operator-(const Point& p1, const Point& p2) {
	auto resta = Point(p1.x + p2.x, p1.y + p2.y);
	return resta;
}



class Shape {
public:
	virtual string draw() = 0;
};

class Circulo :public Shape {
public:
	Circulo(Color* foreColor, Color* backgroundColor, Point PointInicio, Point PointFinal, int shapeID) {
		this->foreColor = foreColor;
		this->backgroundColor = backgroundColor;
		this->PointInicio = PointInicio;
		this->PointFinal = PointFinal;
		this->shapeID = shapeID;
	}
	string draw() {
		return "Circulo";
	};
private:
	Color* foreColor;
	Color* backgroundColor;
	Point PointInicio;
	Point PointFinal;
	int shapeID;
};

class Rectangulo :public Shape {
public:
	Rectangulo(Color* foreColor, Color* backgroundColor, Point PointInicio, Point PointFinal, int shapeID) {
		this->foreColor = foreColor;
		this->backgroundColor = backgroundColor;
		this->PointInicio = PointInicio;
		this->PointFinal = PointFinal;
		this->shapeID = shapeID;
	}
	string draw() {
		return "Rectangulo";
	};
private:
	Color* foreColor;
	Color* backgroundColor;
	Point PointInicio;
	Point PointFinal;
	int shapeID;
};

class Triangulo :public Shape {
public:
	Triangulo(Color* foreColor, Color* backgroundColor, Point PointIncio, Point PointFinal, int shapeID) {
		this->foreColor = foreColor;
		this->backgroundColor = backgroundColor;
		this->PointFinal = PointFinal;
		this->PointInicio = PointInicio;
		this->shapeID = shapeID;
	}
	string draw() {
		return "Triangulo";
	}
private:
	Color* foreColor;
	Color* backgroundColor;
	Point PointInicio;
	Point PointFinal;
	int shapeID;
};

#endif // !SHAPE_H
