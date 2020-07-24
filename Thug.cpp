//
// Created by lior on 04/07/2020.
//

#include "Thug.h"


Thug::Thug(const string& name,const Point& location,int speed,int health) : Agent(name,location,speed,health) {}

Thug::~Thug() {

}

void Thug::update() {

}


void Thug::attack() {
    int h = this->getHealth();
    h--;
    this->setHealth(h);
}

uint Thug::getAttackRange() const {
    return attackRange;
}

void Thug::setAttackRange(uint attackRange) {
    Thug::attackRange = attackRange;
}
