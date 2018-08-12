#include "RightTriangle.h"
#include<math.h>

using namespace std;

RightTriangle::RightTriangle(int h, const string &d) : Triangle(h, h, "RightTriangle", d) { }

RightTriangle::~RightTriangle() = default;

const RightTriangle &RightTriangle::operator=(const RightTriangle &rhs) {
    Triangle::operator=(rhs);
    return *this;
}

void RightTriangle::scale(int n) {
    if (getHeight() + n > 0) {
        setHeight(getHeight() + n);
        setBase(getHeight() + n);
    }
}

double RightTriangle::geoPerimeter() const {
    return (2 + sqrt(2)) * getHeight();  // (2 + sqrt(2)) * h
}

int RightTriangle::scrArea() const {
    return (getHeight() * (getHeight() + 1)) / 2;
}

int RightTriangle::scrPerimeter() const {
    return 3 * (getHeight() - 1);
}

void RightTriangle::draw(Canvas &canvas, int c, int r, char fg, char bg) const {
    for (int h = 0; h < getHeight(); h++) {
        for (int w = 0; w <= h; w++) {
            canvas.putChar(fg, c + h, r + w); // write to right side of c
        }
    }
}
