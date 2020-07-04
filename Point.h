//
// Created by lior on 03/07/2020.
//

#ifndef EX3_SIMMEDIEVAL_POINT_H
#define EX3_SIMMEDIEVAL_POINT_H
#include <iostream>
#include <iomanip>
using namespace std;
class Point {
private:
    double x;
    double y;
public:
    Point();
    Point(double x, double y);
    void print() const;
    bool operator==(const Point& rhs);

};


#endif //EX3_SIMMEDIEVAL_POINT_H
