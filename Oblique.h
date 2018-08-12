#ifndef ISOTRIANGLE_H
#define ISOTRIANGLE_H

#include "Triangle.h"

class Oblique : public Triangle {
public:
    Oblique() = delete;

    Oblique(int h, const std::string &d = "");

    Oblique(const Oblique &) = default;

    virtual ~Oblique();

    const Oblique &operator=(const Oblique &rhs);

    void scale(int n) override;

    double geoPerimeter() const override;

    int scrArea() const override;

    int scrPerimeter() const override;

    /* Draws textual image of the shape on a drawing surface*/
    void draw(Canvas &canvas, int c, int r, char fg, char bg = ' ') const override;
};

#endif // !ISOTRIANGLE_H
