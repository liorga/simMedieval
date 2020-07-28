//
// Created by Evyatar Bhalker & Lior Gal on 7/6/2020.
//

#ifndef EX3_SIMMEDIEVAL_SIMOBJECT_H
#define EX3_SIMMEDIEVAL_SIMOBJECT_H
#include <iostream>
#include "Point.h"
using namespace std;

typedef unsigned int uint;

class SimObject {

public:
    SimObject();
    SimObject(const string& name, const Point& p);
    virtual ~SimObject();

    const string& getName() const;
    Point& getLocation();
    void setLocation(const Point& p);
    virtual void update() = 0;
    virtual void broadcast_current_state();
    virtual void print() = 0;


protected:
    string name;
    Point location;
};


#endif //EX3_SIMMEDIEVAL_SIMOBJECT_H
