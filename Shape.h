#ifndef SHAPE_H
#define SHAPE_H

#include "Canvas.h"

class Shape {
public:
    Shape() = delete;

    Shape(const std::string &sn, const std::string &d);

    Shape(const Shape &) = default;

    virtual ~Shape() = default;

    virtual const Shape &operator=(const Shape &rhs);

    int getIdNum() const;

    std::string getShapeName() const;

    std::string getDescription() const;

    virtual std::string toString() const;

    std::string doubleToString(double d, int p) const; // takes a double and returns a string. p is for precision
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
    std::string shapeName; // generic name
    std::string description;    // variable descriptive name
};

std::ostream &operator<<(std::ostream &ostr, const Shape &rhs);

#endif // !SHAPE_H
