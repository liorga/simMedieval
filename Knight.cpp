//
// Created by lior on 04/07/2020.
//

#include "Knight.h"

Knight::Knight(const string& name,const Point& location,const string & cn, int speed, int health) : Agent(name,location, speed,
                                                                                         health), castle(cn), dst() ,visitedCastles(){
    visitedCastles.push_back(cn);
}

Knight::~Knight() {

}

void Knight::update() {
    if(state== desti){
        if(!location.distance(Model::getInstance().findMapObjectByName(dst)->getLocation())){
            castle = dst;
            visitedCastles.push_back(castle);
            dst = Model::getInstance().getClosestCastle(this->name).getName();
            setDirection(location.angle(Model::getInstance().findMapObjectByName(dst)->getLocation()));

        }
        else{
            advance(Model::getInstance().findMapObjectByName(dst)->getLocation());
        }
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
    setState(desti);
}

const vector<string> &Knight::getVisitedCastles() const {
    return visitedCastles;
}





