#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <ostream>

class Canvas {
public:
    Canvas() = delete;

    Canvas(int c, int r, char ch); // default char is blank space
    explicit Canvas(const Canvas &) = default;

    virtual ~Canvas() = default;

    const Canvas &operator=(const Canvas &rhs);

    int getRowsM() const;

    int getColsN() const;

    const std::vector<std::vector<char> > &getGrid() const;

    void clear(char ch = '.');

    void putChar(char ch, int c, int r);

    char getChar(int c, int r) const;

    void decorate();

    bool valid(int c, int r) const;

protected:
    std::vector<std::vector<char> > grid; // maybe should be made pvt and add pub method setChar(int c, int r)
private:
    int colsN; // number of columns
    int rowsM; // number of rows
    static const char BLANK{' '};
};

const std::ostream &operator<<(std::ostream &os, const Canvas &rhs);

#endif // !CANVAS_H
