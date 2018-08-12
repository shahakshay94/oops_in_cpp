#ifndef SHAPE_H
#define SHAPE_H

#include "Canvas.h"
using namespace std;

class Shape {
public:
    Shape() = delete;

    Shape(const string &nameOfShape, const string &desc);

    Shape(const Shape &) = default;

    virtual ~Shape() = default;

    const Shape &operator=(const Shape &rhs);

    int getIdNum() const;

    string getShapeName() const;

    string getDescription() const;

    string doubleToString(double d, int p) const; // takes a double and returns a string. p is for precision

    virtual string toString() const;

    virtual void scale(int s) = 0;

    virtual double geoArea() const = 0;

    virtual double geoPerimeter() const = 0;

    virtual int scrArea() const = 0;

    virtual int scrPerimeter() const = 0;

    virtual int bBoxWidth() const = 0;

    virtual int bBoxHeight() const = 0;

    /* Draws textual image of the shape on a drawing surface*/
    virtual void draw(Canvas &canvas, int c, int r, char fg, char bg = ' ') const = 0;

private:
    static int nextId; // keeps track of next id number to be assigned
    int idNum; // unique id number
    string shapeName; // generic name
    string description;    // variable descriptive name
};

ostream &operator<<(ostream &ostr, const Shape &rhs);

#endif // !SHAPE_H
