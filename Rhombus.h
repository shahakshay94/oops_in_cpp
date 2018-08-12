#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Shape.h"
#include <iostream>

using namespace std;

class Rhombus : public Shape {
public:
    Rhombus() = delete;

    explicit Rhombus(int rhomDiagonal, const string &desc = "");

    Rhombus(const Rhombus &) = default;

    ~Rhombus() override;

    const Rhombus &operator=(const Rhombus &rhs);

    int getDiagonal() const;

    string toString() const override;

    void scale(int n) override;

    double geoArea() const override;

    double geoPerimeter() const override;

    int scrArea() const override;

    int scrPerimeter() const override;

    int bBoxHeight() const override;

    int bBoxWidth() const override;

    /* Draws textual image of the shape on a drawing surface*/
    void draw(Canvas &canvas, int c, int r, char fg, char bg = ' ') const override;

private:
    int diagonal;
};

ostream &operator<<(ostream &ostr, const Rhombus &rhs);

#endif // !RHOMBUS_H
