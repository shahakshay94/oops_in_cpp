#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

using namespace std;

class Triangle : public Shape {
public:
    Triangle() = delete;

    Triangle(int triangleHeight, int triangleBase, const string &gn, const string &desc = "");

    Triangle(const Triangle &) = default;

    ~Triangle() override;

    const Triangle &operator=(const Triangle &rhs);

    int getHeight() const;

    void setHeight(int h);

    int getBase() const;

    string toString() const override;

    virtual void scale(int n) = 0;

    double geoArea() const override;

    virtual double geoPerimeter() const = 0;

    virtual int scrArea() const = 0;

    virtual int scrPerimeter() const = 0;

    int bBoxWidth() const override;

    int bBoxHeight() const override;

    /* Draws textual image of the shape on a drawing surface*/
    virtual void draw(Canvas &canvas, int c, int r, char fg, char bg = ' ') const = 0;

protected:
    void setBase(int b);

private:
    int height;
    int base;
};

ostream &operator<<(ostream &ostr, const Triangle &rhs);

#endif // !TRIANGLE_H
