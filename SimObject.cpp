//
// Created by lior on 04/07/2020.
//

#include "SimObject.h"
#include <typeinfo>
SimObject::SimObject() {

}

SimObject::SimObject(const string& name) : name(name) {}


SimObject::~SimObject() {

}

void SimObject::broadcest_current_state() {

}

const string& SimObject::getName() const {
    return name;
}

void SimObject::setLocation(const Point &p) {
    location = p;
}

Point &SimObject::getLocation() {
    return location;
}

ostream &operator<<(ostream &os, const SimObject &object) {
    os << typeid(object).name()<<" "<< object.getName() << " at ";
    return os;
}

