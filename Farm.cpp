//
// Created by lior on 04/07/2020.
//

#include "Farm.h"

Farm::Farm(const string& name, const Point& location,uint inventory, uint rate) : Structure(name, location,inventory), rate(rate) {}

Farm::~Farm() {

}

uint Farm::getRate() const {
    return rate;
}

void Farm::setRate(uint rate) {
    Farm::rate = rate;
}

void Farm::update() {
    this->inventory+=rate;

}

void Farm::operator++() {

}
