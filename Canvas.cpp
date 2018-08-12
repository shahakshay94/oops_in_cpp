#include "Canvas.h"
#include <iostream>
#include <cassert>

using namespace std;

Canvas::Canvas(int c, int r, char ch) : colsN(c), rowsM(r), grid(c, vector<char>(r, ch)) {
    assert(c > 0 && r > 0);
}

const Canvas &Canvas::operator=(const Canvas &rhs) { // NOLINT
    if (this == &rhs) return *this;
    colsN = rhs.colsN;
    rowsM = rhs.rowsM;
    grid = rhs.grid;
    return *this;
}

int Canvas::getRowsM() const {
    return rowsM;
}

int Canvas::getColsN() const {
    return colsN;
}

const std::vector<std::vector<char>> &Canvas::getGrid() const {
    return grid;
}

void Canvas::clear(char ch) {
    for (auto rowIt = grid.begin(), rowEnd = grid.end(); rowIt != rowEnd; ++rowIt) {
        for (auto colIt = rowIt->begin(), colEnd = rowIt->end(); colIt != colEnd; ++colIt) {
            *colIt = ch;
        }
    }
}

void Canvas::putChar(char ch, int c, int r) {
    if (valid(c, r))
        grid[c][r] = ch;
}

char Canvas::getChar(int c, int r) const {
    if (valid(c, r))
        return grid[c][r];
    else {
        cerr << "Error. Invalid column or row" << endl;
        return '\0';
    }

}

void Canvas::decorate() {// no decoration for plain canvas
}

bool Canvas::valid(int c, int r) const {
    if (c >= 0 && r >= 0) // not negative and starts from [0,0]
        return c < getColsN() && r < getRowsM(); // in column range and in row range.
    else
        return false;
}

const ostream &operator<<(ostream &os, const Canvas &rhs) {
    for (auto rowIt = rhs.getGrid().begin(), rowEnd = rhs.getGrid().end(); rowIt != rowEnd; ++rowIt) {
        for (auto colIt = rowIt->begin(), colEnd = rowIt->end(); colIt != colEnd; ++colIt) {
            os << *colIt;
        }
        os << endl;
        // another way:
        //const char * p = rowIt->data();
        //for (size_t i = 0; i < rowIt->size(); ++i)
        //{
        //	os << *p;
        //	++p;
        //}
    }
    return os;
}
