#include "Oblique.h"
#include<cmath>

using namespace std;

Oblique::Oblique(int base, const string &d) : Triangle((base + 1) / 2, base % 2 == 0 ? base + 1 : base, "Oblique", d) {
}

Oblique::~Oblique() = default;

const Oblique &Oblique::operator=(const Oblique &rhs) {
    Triangle::operator=(rhs);
    return *this;
}

void Oblique::scale(int n) {
    if (getHeight() + n > 0) {
        setHeight(getHeight() + n);
        setBase(2 * getHeight() - 1);
    }
}

double Oblique::geoPerimeter() const {
    double partial{0.25 * getBase() * getBase()}; // 0.25 * b^2
    partial += getHeight() * getHeight();  // 0.25 * b^2 + h^2
    return getBase() + 2 * sqrt(partial);  // b + 2* sqrt(0.25 * b^2 + h^2)
}

int Oblique::scrArea() const {
    return getHeight() * getHeight();
}

int Oblique::scrPerimeter() const {
    return 4 * (getHeight() - 1);
}

/* draw textual image of the shape on a drawing surface */
void Oblique::draw(Canvas &canvas, int c, int r, char fg, char bg) const {
    /*c += getBase(); // fixes position, aligns leftmost char to c, instead of c as center.

    for (int h = 0; h < getHeight(); h++)
    {
            for (int w = 0; w <= h; w++)
            {
                canvas.putChar(fg, c + w, r + h); // write to right side
                canvas.putChar(fg, c - w, r + h); // write to left side
            }

    }*/
    int rows = getHeight();
    for (int i = 1, k = 0; i <= rows; ++i, k = 0) {
        int space = 1;
        for (; space <= rows - i; ++space);
        int z = 0;
        while (k != 2 * i - 1) {
            canvas.putChar(fg, c + i, r + space - 1 + z);
            ++k;
            ++z;
        }
    }
}
