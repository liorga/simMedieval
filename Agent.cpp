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
