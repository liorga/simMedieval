//
// Created by lior on 03/07/2020.
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
    static double parseX(const string& arg);
    static double parseY(const string& arg);
    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);

private:
    double x;
    double y;


};


#endif //EX3_SIMMEDIEVAL_POINT_H
