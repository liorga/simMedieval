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
    this->health = health;
}

const Agent::State Agent::getState() const {
    return state;
}

void Agent::setState(State s) {
    this->state = s;
}
// remove Moving object and deal with consequences
Agent::Agent( const string& name,Point location, int speed, int health) :SimObject(name, location), health(health),speed(speed) ,state(stopped){}





void Agent::stop() {
 setState(stopped);
}



void Agent::course() {
    setState(Moving);
}

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

    this->direction = direction >= DEGREES ? direction - DEGREES : direction; // maybe check in model and throw exception?

}

double Agent::getDirection() {
	return this->direction < 90 ? this->direction + 270 : this->direction - 90 ;
}

void Agent::position(const Point &p) {
    dest = new Point(p);
}

void Agent::print() {

    string stateArr[3] = {"Stopped", "Dead", "Moving in "+to_string(this->getDirection())+" deg, speed "+to_string(speed)+" km/h"};
    string type = typeid(*this).name();
    type = type.substr(1,type.length()-1);
    cout << type << " " << this->getName() << " at " << this->location << "," << stateArr[getState()] <<endl;

}

void Agent::update() {
    if (state == Moving &&dest != nullptr){
        advance(*dest);
    }
}
void Agent::advance(const Point& dst){
    if(location.distance(dst) > 0) {
        if (location.distance(dst) <= speed) {
            this->setLocation(dst);
        } else {
            location.setRadius(speed, direction);
        }
    }
}









