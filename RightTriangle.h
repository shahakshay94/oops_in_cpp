#ifndef RIGHTANGLE_H
#define RIGHTANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle {
public:

    RightTriangle() = delete;

    RightTriangle(int h, const std::string &d = "");

    RightTriangle(const RightTriangle &) = default;

    virtual ~RightTriangle();

    const RightTriangle &operator=(const RightTriangle &rhs);

    void scale(int n);

    double geoPerimeter() const;

    int scrArea() const;

    int scrPerimeter() const;

    /* Draws textual image of the shape on a drawing surface*/
    void draw(Canvas &canvas, int c, int r, char fg, char bg = ' ') const;
};

#endif // !RIGHTANGLE_H
