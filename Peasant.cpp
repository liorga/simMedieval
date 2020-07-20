//
// Created by lior on 04/07/2020.
//

#include "Peasant.h"


Peasant::Peasant(const string& name,const Point& location  ,int speed, int health) : Agent(location, speed, name,
                                                                                           health) {
    bag = ZERO; // peasant start with an empty bag
}

Peasant::~Peasant() {

}

void Peasant::update() {

}



void Peasant::start_working(string farm_src, string castle_dest) {

}

void Peasant::attack() {
    setBeg(ZERO);
}

uint Peasant::getBag() const {
    return bag;
}

void Peasant::setBeg(uint beg) {
    Peasant::beg = beg;
}

