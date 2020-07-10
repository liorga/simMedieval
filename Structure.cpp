//
// Created by lior on 04/07/2020.
//

#include "Structure.h"

Structure::Structure(const string& name, const Point& location ,  uint inventory) : SimObject(name), location(location),inventory(inventory) {}

Structure::~Structure() {

}

Point& Structure::getLocation() {
    Point p(0,0);
    return p;
}

void Structure::update() {

}

void Structure::deposit() {

}

uint Structure::withdrew() {
    return 0;
}

void Structure::setLocation(const Point& location) {
    Structure::location = location;
}

uint Structure::getInventory() const {
    return inventory;
}

void Structure::setInventory(uint inventory) {
    Structure::inventory = inventory;
}
