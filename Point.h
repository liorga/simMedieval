//
// Created by Evyatar Bhalker & Lior Gal on 7/6/2020.
//

#ifndef EX3_SIMMEDIEVAL_POINT_H
#define EX3_SIMMEDIEVAL_POINT_H
#include <iostream>
#include <iomanip>
using namespace std;
class Point {
public:
    Point();
    Point(double x, double y);
    void print() const;
    bool operator==(const Point& rhs);
    static double parseX( const std::string& );
    static double parseY( const std::string&);



    bool operator<(const Point &rhs) const;

    bool operator>(const Point &rhs) const;

    bool operator<=(const Point &rhs) const;

    bool operator>=(const Point &rhs) const;
    double getX() const;
    void setX(double x);

    double getY() const;

    void setY(double y);
    pair<double, double> get() const;
    double distance(const Point& p) const;
    double angle(const Point& p) const;
    double getRadius() const;

    friend ostream &operator<<(ostream &os, const Point &point);

    void setRadius(double d,double direct);

private:
    double x;
    double y;

    double getAngle();
};


#endif //EX3_SIMMEDIEVAL_POINT_H
