//
// Created by Evyatar Bhalker & Lior Gal on 7/6/2020.
//

#include "Structure.h"
#include <typeinfo>
Structure::Structure(const string& name, const Point& location ,  uint inventory) : SimObject(name,location),inventory(inventory) {}

Structure::~Structure() {

}


void Structure::update() {

}

void Structure::deposit() {

}

uint Structure::withdraw() {
    return 0;
}


uint Structure::getInventory() const {
    return inventory;
}

void Structure::setInventory(uint inventory) {
    Structure::inventory = inventory;
}

void Structure::print() {
    string type = typeid(*this).name();
    type = type.substr(1,type.length()-1);
    cout << type << " " << this->getName() << " at position" << this->location << " , Inventory: " << this->inventory ;
}

