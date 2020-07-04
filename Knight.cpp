//
// Created by lior on 04/07/2020.
//

#include "Knight.h"

Knight::Knight(const string& name,const Point& location, int speed, int health) : Agent(location, speed, name,
                                                                                         health) {}

Knight::~Knight() {

}

void Knight::update() {

}

Point& Knight::getLocation() {
    Point p(0,0);
    return p;
}
