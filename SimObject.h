//
// Created by lior on 04/07/2020.
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
    SimObject(const string& name);
    virtual ~SimObject();

    const string& getName() const;
    Point& getLocation();
    void setLocation(const Point& p);
    virtual void update() = 0;
    void broadcest_current_state();

    virtual ostream& operator<<(ostream &os, const SimObject &object);

protected:
    string name;
    Point location;
};


#endif //EX3_SIMMEDIEVAL_SIMOBJECT_H
