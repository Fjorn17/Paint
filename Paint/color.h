#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>

using namespace std;

class Color {
public:
    static const int MAX = 0xffff;
    Color(int red, int green, int blue, int alpha = MAX);
 
    static const Color red;
    static const Color green;
    static const Color blue;
    static const Color white;
    static const Color black;
    

private:
    int m_red;
    int m_green;
    int m_blue;
    int m_alpha;
};

const Color Color::red(MAX, 0, 0);
const Color Color::green(0, MAX, 0);
const Color Color::blue(0, 0, MAX);
const Color Color::white(MAX, MAX, MAX);
const Color Color::black(0, 0, 0);



#endif //!COLOR_H