//
//Created by Evyatar Bhalker & Lior Gal on 7/6/2020.
//

#include "Agent.h"



Agent::~Agent() {
	delete dest;
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
Agent::Agent( const string& name,Point location, int speed, int health) :SimObject(name, location), health(health),speed(speed) ,state(stopped){
    dest = new Point();
}





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
	return DEGREES -this->direction + 90;
}

void Agent::position(const Point &p) {
    dest = new Point(p);
    setState(pos);
    setDirection(this->location.angle(*dest));
}

void Agent::print() {

    string stateArr[4] = {"Stopped", "Dead", "Moving in "+to_string(this->getDirection())+" deg, speed "+to_string(speed)+" km/h",
                          "Heading to ("+ to_string(this->dest->getX())+", "+to_string(this->dest->getY())+") , speed "+to_string(speed)+ " km/h"};
    string type = typeid(*this).name();
    type = type.substr(1,type.length()-1);
    cout << setprecision(2) << type << " " << this->getName() << " at " << this->location << "," << stateArr[getState()] << " " << to_string(health);

}

void Agent::update() {
    if (state == Moving){
    	this->location.setRadius(speed,this->direction);
    } else if(dest && state == pos){
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

void Agent::destination(const string &SiteName) {

}









