//
// Created by lior on 04/07/2020.
//

#include "Peasant.h"


Peasant::Peasant(const string& name,const Point& location  ,int speed, int health) : Agent(location, speed, name,
                                                                                           health) {
    beg = 0; // peasant start with an empty beg
}

Peasant::~Peasant() {

}

void Peasant::update() {

}

Point& Peasant::getLocation() {
    Point p(0,0);
    return p;
}

void Peasant::start_working(string farm_src, string castle_dest) {

}

