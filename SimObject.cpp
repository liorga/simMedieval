//
// Created by lior on 04/07/2020.
//

#include "SimObject.h"

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
