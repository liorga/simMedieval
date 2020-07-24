//
// Created by lior on 04/07/2020.
//

#include "Agent.h"



Agent::~Agent() {

}

int Agent::getHealth() const {
    return health;
}

void Agent::setHealth(int health) {
    Agent::health = health;
}

const Agent::State Agent::getState() const {
    return state;
}

void Agent::setState(State s) {
    Agent::state = state;
}
// remove Moving object and deal with consequences
Agent::Agent( const string& name,Point location, int speed, int health) :SimObject(name, location), health(health),speed(speed) {}




void Agent::move_to() {

}

void Agent::stop() {
 setState(stopped);
}



void Agent::course() {}

void Agent::attack() {}

Agent &Agent::operator++() {
    ++health;
    return *this;
}

Agent &Agent::operator--() {
    --health;
    if(health == 0){
        setState(dead);
    }
    return *this;
}

void Agent::setSpeed(const double s) {
    speed = s;
}

void Agent::setDirection(double direction) {

    this->direction = direction>=DEGREES? direction-DEGREES: direction; // maybe check in model and throw exception?

}

void Agent::position(const Point &p) {
    dest = p;
}




