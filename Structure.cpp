//
// Created by lior on 04/07/2020.
//

#include "Structure.h"

Structure::Structure(const string& name, const Point& location ,  uint inventory) : SimObject(name), location(location),inventory(inventory) {}

Structure::~Structure() {

}


void Structure::update() {

}

void Structure::deposit() {

}

uint Structure::withdrew() {
    return 0;
}


uint Structure::getInventory() const {
    return inventory;
}

void Structure::setInventory(uint inventory) {
    Structure::inventory = inventory;
}
