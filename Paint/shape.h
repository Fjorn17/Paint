#ifndef SHAPE_H
#define SHAPE_H 


#include "color.h"
#include "punto.h"

#include <string>
#include <iostream>

using namespace std;

class Shape {
public:
	virtual string draw() = 0;
};

class Circulo :public Shape {
public:
	Circulo(Color* foreColor, Color* backgroundColor, Punto puntoInicio, Punto puntoFinal, int shapeID) {
		this->foreColor = foreColor;
		this->backgroundColor = backgroundColor;
		this->puntoInicio = puntoInicio;
		this->puntoFinal = puntoFinal;
		this->shapeID = shapeID;
	}
	string draw() {
		return "Circulo";
	};
private:
	Color* foreColor;
	Color* backgroundColor;
	Punto puntoInicio;
	Punto puntoFinal;
	int shapeID;
};

class Rectangulo :public Shape {
public:
	Rectangulo(Color* foreColor, Color* backgroundColor, Punto puntoInicio, Punto puntoFinal, int shapeID) {
		this->foreColor = foreColor;
		this->backgroundColor = backgroundColor;
		this->puntoInicio = puntoInicio;
		this->puntoFinal = puntoFinal;
		this->shapeID = shapeID;
	}
	string draw() {
		return "Rectangulo";
	};
private:
	Color* foreColor;
	Color* backgroundColor;
	Punto puntoInicio;
	Punto puntoFinal;
	int shapeID;
};

class Triangulo :public Shape {
public:
	Triangulo(Color* foreColor, Color* backgroundColor, Punto puntoIncio, Punto puntoFinal, int shapeID) {
		this->foreColor = foreColor;
		this->backgroundColor = backgroundColor;
		this->puntoFinal = puntoFinal;
		this->puntoInicio = puntoInicio;
		this->shapeID = shapeID;
	}
	string draw() {
		return "Triangulo";
	}
private:
	Color* foreColor;
	Color* backgroundColor;
	Punto puntoInicio;
	Punto puntoFinal;
	int shapeID;
};

#endif // !SHAPE_H
