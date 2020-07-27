//
// Created by lior on 04/07/2020.
//

#include "Peasant.h"


Peasant::Peasant(const string& name, Point* location  , int speed, int health) : Agent(name, *location, speed, health) ,VisitedFarm(false),farm(),castle(){
    bag = ZERO; // peasant start with an empty bag
}

Peasant::~Peasant() {

}

void Peasant::update() {

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

void Peasant::start_working(const Point &farm_src, const Point &castle_dest) {
    setFarm(farm_src);
    setCastle(castle_dest);
    setDirection(location.angle(farm_src));


}

void Peasant::setFarm(const Point &point) {

}

void Peasant::setCastle(const Point &point) {

}



