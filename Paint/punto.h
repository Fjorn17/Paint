#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

class Punto {
private:
	int x;
	int y;
public:
	Punto() {
		x = 0;
		y = 0;
	}
	Punto(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }

	friend Punto& operator+(const Punto& p1, const Punto& p2);
	friend Punto& operator-(const Punto& p1, const Punto& p2);
};
Punto& operator+(const Punto& p1, const Punto& p2) {
	auto suma = Punto(p1.x + p2.x, p1.y + p2.y);
	return suma;
}
Punto& operator-(const Punto& p1, const Punto& p2) {
	auto resta = Punto(p1.x + p2.x, p1.y + p2.y);
	return resta;
}

#endif //!PUNTO_H