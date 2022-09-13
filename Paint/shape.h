#ifndef SHAPE_H
#define SHAPE_H 

#include <string>
#include <iostream>
#include <vector>

using namespace std;



class Color
{
public:
	 Color red() { return Color(255, 0, 0); }
	 Color green() { return Color(0, 255, 0); }
	 Color blue() { return Color(0, 0, 255); }
	 Color black() { return Color(0, 0, 0); }
	 Color white() { return Color(255, 255, 255); }

	 Color() :r(0), g(0), b(0),a(255) {};

	constexpr Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
		: r(r), g(g), b(b), a(a)
	{}
	Color& operator=(string color) {
		Color sol;
		if (color == "red") {
			sol = red();
			return sol;
		}
		if (color == "green") {
			sol = green();
			return sol;
		}
		if (color == "blue") {
			sol = blue();
			return sol;
		}
		if (color == "black") {
			sol = black();
			return sol;
		}
		else {
			sol = white();
			return sol;
		}
	}
	Color(string color) { *this = color; }

private:
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
	Point(int x=0, int y=0):x(x),y(y) {}
	int getX() { return x; }
	int getY() { return y; }

	Point& operator+(const Point& other);
	Point& operator-(const Point& other);
	Point& operator=(vector<int> other);
};

class Shape {
public:
	virtual ~Shape() {}
	virtual string draw() = 0;
};

class Circulo :public Shape {
public:
	Circulo(Color foreColor, Color backgroundColor, Point PointInicio, Point PointFinal, string shapeID):
		foreColor(foreColor), backgroundColor(backgroundColor), PointInicio(PointInicio), PointFinal(PointFinal), shapeID(shapeID){}
	virtual ~Circulo() {}
	string draw() {
		return "Circulo";
	};
private:
	Color foreColor;
	Color backgroundColor;
	Point PointInicio;
	Point PointFinal;
	string shapeID;
};

class Rectangulo :public Shape {
public:
	Rectangulo(Color foreColor, Color backgroundColor, Point PointInicio, Point PointFinal, string shapeID) :
		foreColor(foreColor), backgroundColor(backgroundColor), PointInicio(PointInicio), PointFinal(PointFinal), shapeID(shapeID) {}
	string draw() {
		return "Rectangulo";
	};
private:
	Color foreColor;
	Color backgroundColor;
	Point PointInicio;
	Point PointFinal;
	string shapeID;
};

class Triangulo :public Shape {
public:
	Triangulo(Color foreColor, Color backgroundColor, Point PointIncio, Point PointFinal) :
		foreColor(foreColor), backgroundColor(backgroundColor), PointInicio(PointInicio), PointFinal(PointFinal) {}
	string draw() {
		return "Triangulo";
	}
private:
	Color foreColor;
	Color backgroundColor;
	Point PointInicio;
	Point PointFinal;
	string shapeID;
};

#endif // !SHAPE_H
