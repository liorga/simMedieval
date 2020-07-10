//
// Created by lior on 04/07/2020.
//

#include "Thug.h"


Thug::Thug(const string& name,const Point& location,int speed, int health) : Agent(location, speed, name, health) {}

Thug::~Thug() {

}

void Thug::update() {

}

Point& Thug::getLocation() {
    Point p(0,0);
    return p;
}

void Thug::attack() {
    int h = this->getHealth();
    h--;
    this->setHealth(h);
}
