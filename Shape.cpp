#include "Shape.h"
//#include <typeinfo>
#include <iostream>
#include <sstream>

using namespace std;

int Shape::nextId = 1;

Shape::Shape(const string &sn, const string &d) : shapeName(sn), description(d), idNum(nextId++) {
    if (d.empty())
        description = "Generic " + shapeName;
}

const Shape &Shape::operator=(const Shape &rhs) {
    if (this == &rhs) return *this;
    shapeName = rhs.shapeName;
    description = rhs.description;
    return *this;
}

int Shape::getIdNum() const {
    return idNum;
}

string Shape::getShapeName() const {
    return shapeName;
}

string Shape::getDescription() const {
    return description;
}

std::string Shape::toString() const {
    string temp{"Shape Information\n-----------------"};
    temp += "\nStatic Type:   ";
    temp.append(typeid(this).name());
    temp += "\nDynamic Type:  ";
    temp.append(typeid(*this).name());
    temp += "\nShape name:  " + getShapeName();
    temp += "\nDescription:   " + getDescription();
    temp += "\nid:            ";
    temp.append(to_string(getIdNum()));
    return temp;
}

string Shape::doubleToString(double d, int p) const {
    ostringstream s;
    s.precision(p);
    s << fixed << d;
    string temp{s.str()};
    return temp;
}

ostream &operator<<(ostream &ostr, const Shape &rhs) {
    const Shape *rhsPtr = &rhs;
    ostr << "Shape Information"
         << "\n-----------------"
         << "\nStatic Type:   " << typeid(rhsPtr).name()
         << "\nDynamic Type:  " << typeid(*rhsPtr).name()
         << "\nGeneric name:  " + rhs.getShapeName()
         << "\nDescription:   " + rhs.getDescription()
         << "\nid:            " + to_string(rhs.getIdNum());
    return ostr;
}
