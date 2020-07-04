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
