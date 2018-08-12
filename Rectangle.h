#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iostream>

using namespace std;

class Rectangle : public Shape {
public:
    Rectangle() = delete;

    Rectangle(int rectHeight, int rectWidth, const string &d = "");

    Rectangle(const Rectangle &) = default;

    ~Rectangle() override;

    const Rectangle &operator=(const Rectangle &rhs);

    int getHeight() const;

    int getWidth() const;

    string toString() const override;

    void scale(int n) override;

    double geoArea() const override;

    double geoPerimeter() const override;

    int scrArea() const override;

    int scrPerimeter() const override;

    int bBoxHeight() const override;

    int bBoxWidth() const override;

    /* Draws textual image of the shape on a drawing surface*/
    void draw(Canvas &canvas, int c, int r, char fg, char bg = '*') const override;

private:
    int height;
    int width;
};

ostream &operator<<(ostream &ostr, const Rectangle &rhs);

#endif // !RECTANGLE_H
