//
// Created by lior on 04/07/2020.
//

#include "Peasant.h"


Peasant::Peasant(const string& name, Point* location  , int speed, int health) : Agent(name, *location, speed, health) {
    bag = ZERO; // peasant start with an empty bag
}

Peasant::~Peasant() {

}

void Peasant::update() {

}



void Peasant::start_working(string farm_src, string castle_dest) {

}

void Peasant::attack() {
    setBag(ZERO);
}

uint Peasant::getBag() const {
    return bag;
}

void Peasant::setBag(uint bag) {
    Peasant::bag = bag;
}

