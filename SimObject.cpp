//
// Created by lior on 04/07/2020.
//

#include "SimObject.h"
#include <typeinfo>
SimObject::SimObject() {

}

SimObject::SimObject(const string& name, const Point& p) : name(name), location(p) {}


SimObject::~SimObject() {

}

void SimObject::broadcast_current_state() {

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


