//
// Created by lior on 03/07/2020.
//
#include <cmath>
#include "Point.h"
const double pi = 2. * atan2(1., 0.);
Point::Point() {
    x = 0.0;
    y = 0.0;
}

Point::Point(double x, double y) : x(x) , y(y) {

}

void Point::print() const {
    std::cout << setprecision(2) << "(" << x << ", " << y << ")" << " ";
}

bool Point::operator==(const Point &rhs) {
    return x == rhs.x && y == rhs.y;
}

double Point::parseX(const string& arg) {
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
pair<double, double> Point::get() const{
    return pair<double,double>(x,y);
}

ostream &operator<<(ostream &os, const Point &point) {
    os <<  "(" << setprecision(2)<<point.x << ", " << point.y << ")"  << " ";;
    return os;
}

double Point::distance(const Point &p) const {
    double newX= x-p.getX();
    double newY = y-p.getX();
    return sqrt((newX*newX) + (newY*newY));
}
double to_radians(double theta_d)
{
    return theta_d * pi / 180.0;
}

double Point::angle(const Point &p) const {
    double phi =  atan2((p.getY()-this->y),(p.getX()-this->getX()));
    if (phi<0.)
        phi = 2.*pi +phi;
    return (phi *180/pi);
}

void Point::setRadius(double d, double direct) {
        this->x += d*cos(to_radians(direct));
        this->y += d*sin(to_radians(direct));
}




//return both x and y