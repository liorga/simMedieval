//
// Created by lior on 04/07/2020.
//

#include "Moving_Object.h"

Moving_Object::Moving_Object() {}

Moving_Object::~Moving_Object() {

}

const Point& Moving_Object::getLocation() const {
    return location;
}

void Moving_Object::setLocation(const Point& location) {
    Moving_Object::location = location;
}

const Point& Moving_Object::getDestionation() const {
    return destionation;
}

void Moving_Object::setDestionation(const Point& destionation) {
    Moving_Object::destionation = destionation;
}

int Moving_Object::getSpeed() const {
    return speed;
}

void Moving_Object::setSpeed(int speed) {
    Moving_Object::speed = speed;
}

void Moving_Object::start_moving() {

}

Moving_Object::Moving_Object(const Point& location, int speed) : location(location), speed(speed) {}
