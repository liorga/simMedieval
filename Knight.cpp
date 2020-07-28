//
// Created by Evyatar Bhalker & Lior Gal on 7/6/2020.
//

#include "Knight.h"

Knight::Knight(const string& name,const Point& location,const string & cn, int speed, int health) : Agent(name,location, speed,
                                                                                         health), castle(cn), dst() ,visitedCastles(), DoneTour(false){
    visitedCastles.push_back(cn);
}

Knight::~Knight() {

}

void Knight::update() {
    if(state== desti){
        if(location.distance(Model::getInstance().findMapObjectByName(dst)->getLocation()) == 0){
            if(DoneTour){
                setState(stopped);
                setVisit();
                DoneTour = false;
                return;
            }
            castle = dst;
            visitedCastles.push_back(castle);
            dst = Model::getInstance().getClosestCastle(this->name).getName();
            setDirection(location.angle(Model::getInstance().findMapObjectByName(dst)->getLocation()));
        }
        advance(Model::getInstance().findMapObjectByName(dst)->getLocation());
    }

}

void Knight::print() {
    string type = typeid(*this).name();
    type = type.substr(1,type.length()-1);

    if(state == desti) {
        if (!this->getLocation().distance(Model::getInstance().findMapObjectByName(castle)->getLocation())) {
            cout << type << " " << this->getName() << " at " << castle << ", Heading to " << dst << ", speed "
                 << to_string(speed) << " km/h";
        } else {
            cout << type << " " << this->getName() << " at " << getLocation() << ", Heading to " << dst << ", speed "
                 << to_string(speed) << " km/h";
        }
    }
    else {
        Agent::print();
    }
}

void Knight::destination(const string &SiteName) {
    dst = SiteName;
    setDirection(this->location.angle(Model::getInstance().findMapObjectByName(dst)->getLocation()));
    setState(desti);
}

const vector<string> &Knight::getVisitedCastles() const {
    return visitedCastles;
}

void Knight::setVisit() {
        visitedCastles.clear();
        visitedCastles.push_back(castle);
}

void Knight::setTour(bool val) {
    DoneTour = val;
}





