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
    SimObject(const string& name, const Point& p);
    virtual ~SimObject();

    const string& getName() const;
    Point& getLocation();
    void setLocation(const Point& p);
    virtual void update() = 0;
    virtual void broadcast_current_state();

    friend ostream &operator<<(ostream &os, const SimObject &object);

protected:
    string name;
    Point location;
};


#endif //EX3_SIMMEDIEVAL_SIMOBJECT_H
