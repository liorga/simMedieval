//
// Created by lior on 03/07/2020.
//
#include "Point.h"

Point::Point() {
    x = 0.0;
    y = 0.0;
}

Point::Point(double x, double y) : x(x) , y(y) {

}

void Point::print() const {
    std::cout << setprecision(2) << "(" << x << ", " << y << ")";
}

bool Point::operator==(const Point &rhs) {
    return x == rhs.x && y == rhs.y;
}

double Point::parseX(const string & arg) {
    int start = arg.find_first_of("(")+1;
    int len = arg.find_first_of(",")-start;
    return std::stod(arg.substr(start,len ));
}

double Point::parseY(const string & arg) {
    int start = arg.find_first_of(",")+1;
    int len = arg.find_first_of(")")-start;
    return std::stod(arg.substr(start,len ));
}

double Point::getX() const {
    return x;
}

void Point::setX(double x) {
    Point::x = x;
}

double Point::getY() const {
    return y;
}

void Point::setY(double y) {
    Point::y = y;
}

bool Point::operator<(const Point &rhs) const {
    if (x < rhs.x)
        return true;
    if (rhs.x < x)
        return false;
    return y < rhs.y;
}

bool Point::operator>(const Point &rhs) const {
    return rhs < *this;
}

bool Point::operator<=(const Point &rhs) const {
    return !(rhs < *this);
}

bool Point::operator>=(const Point &rhs) const {
    return !(*this < rhs);
}
