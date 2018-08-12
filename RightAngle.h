#ifndef RIGHTANGLE_H
#define RIGHTANGLE_H

#include "Triangle.h"

class RightAngle : public Triangle {
public:

    RightAngle() = delete;

    RightAngle(int h, const std::string &d = "");

    RightAngle(const RightAngle &) = default;

    virtual ~RightAngle();

    const RightAngle &operator=(const RightAngle &rhs);

    void scale(int n);

    double geoPerimeter() const;

    int scrArea() const;

    int scrPerimeter() const;

    /* Draws textual image of the shape on a drawing surface*/
    void draw(Canvas &canvas, int c, int r, char fg, char bg = ' ') const;
};

#endif // !RIGHTANGLE_H
