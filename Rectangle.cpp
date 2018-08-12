#include "Rectangle.h"
#include <cassert>

using namespace std;

Rectangle::Rectangle(int rectHeight, int rectWidth, const string &d) : Shape("Rectangle", d), height(rectHeight), width(rectWidth) {
    assert(height > 0 && width > 0);
}

Rectangle::~Rectangle() = default;

const Rectangle &Rectangle::operator=(const Rectangle &rhs) {
    if (this == &rhs) return *this;
    Shape::operator=(rhs);
    height = rhs.height;
    width = rhs.width;
    return *this;
}

int Rectangle::getHeight() const {
    return height;
}

int Rectangle::getWidth() const {
    return width;
}

string Rectangle::toString() const {
    //cout << "Rectangle::toString()" << endl;
    string temp{Shape::toString()};
    temp.append("\nB. box width:  " + to_string(width));
    temp.append("\nB. box height:  " + to_string(height));
    temp.append("\nScr area:      " + to_string(scrArea()));
    temp.append("\nGeo area:      " + doubleToString(geoArea(), 2));
    temp.append("\nScr perimeter: " + to_string(scrPerimeter()));
    temp.append("\nGeo perimeter: " + doubleToString(geoPerimeter(), 2));
    return temp;
}

void Rectangle::scale(int n) {
    if (height + n >= 1 && width + n >= 1) {
        height += n;
        width += n;
    }
}

double Rectangle::geoArea() const {
    return getHeight() * getWidth();
}

double Rectangle::geoPerimeter() const {
    return 2 * (getHeight() + getWidth());
}

int Rectangle::scrArea() const {
    return getHeight() * getWidth();
}

int Rectangle::scrPerimeter() const {
    return 2 * (getHeight() + getWidth()) - 4;
}

int Rectangle::bBoxHeight() const {
    return getHeight();
}

int Rectangle::bBoxWidth() const {
    return getWidth();
}

void Rectangle::draw(Canvas &canvas, int c, int r, char fg, char bg) const {
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            canvas.putChar(fg, c + w, r + h);
        }
    }
}

ostream &operator<<(ostream &ostr, const Rectangle &rhs) {
    const Shape *shapePtr = &rhs;
    ostr << *shapePtr;
    ostr.precision(2);
    ostr << "\nB. box width:  " << rhs.bBoxWidth()
         << "\nB. box height:  " << rhs.bBoxHeight()
         << "\nScr area:      " << rhs.scrArea()
         << "\nGeo area:      " << fixed << rhs.geoArea()
         << "\nScr Perimeter: " << rhs.scrPerimeter()
         << "\nGeo Perimeter: " << rhs.geoPerimeter();
    return ostr;
}
