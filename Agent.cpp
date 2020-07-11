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

const string& Agent::getState() const {
    return state;
}

void Agent::setState(const string& state) {
    Agent::state = state;
}

Agent::Agent(const Point& location, int speed, const string& name, int health) : Moving_Object(location, speed),
                                                                                 SimObject(name), health(health) {}

Point &Agent::getLocation() {
    return SimObject::getLocation();
}

void Agent::setLocation() {

}

void Agent::move_to() {

}

void Agent::stop() {

}

void Agent::destination(const Point &p) {

}

void Agent::course() {

}

void Agent::attack() {

}

Agent &Agent::operator++() {
    ++health;
    return *this;
}

Agent &Agent::operator--() {
    --health;
    if(health == 0){
        setState("Dead");
    }
    return *this;
}

ostream &Agent::operator<<(ostream &os,  SimObject &object) {
    Agent& tmp = dynamic_cast<Agent&>(object);
    SimObject::operator<<(os, object);
    os <<tmp.getLocation()<< ", " << state<<std::endl;
}
