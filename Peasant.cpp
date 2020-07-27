//
// Created by lior on 04/07/2020.
//

#include "Peasant.h"


Peasant::Peasant(const string& name, Point* location  , int speed, int health) : Agent(name, *location, speed, health) ,VisitedFarm(false),farm(),castle(){
    bag = ZERO; // peasant start with an empty bag
}

Peasant::~Peasant() {

}

void Peasant::update() {
    if (this->getState()==Working){
        if(!VisitedFarm){
            Farm& f = dynamic_cast<Farm&>(*(Model::getInstance().findMapObjectByName(farm)));
            if(this->location.distance(f.getLocation()) == 0){
                uint available_space = MAX_BAG-bag;
                if(f.getInventory()<= available_space){
                    bag += f.getInventory();
                    f.setInventory(0);
                }
                else{
                    bag+= available_space;
                    f.setInventory(f.getInventory()-available_space);
                }

                VisitedFarm = true;

                setDirection(location.angle(Model::getInstance().findMapObjectByName(castle)->getLocation()));

            }
            else if (this->location.distance(f.getLocation()) <= speed){
                this->setLocation(f.getLocation());
            }else{
                this->location.setRadius(speed,direction); // new point at direction of farm check.
            }
        }
        else{
            Castle& c=dynamic_cast<Castle&>(*(Model::getInstance().findMapObjectByName(castle)));
            if(this->location.distance(c.getLocation()) == 0){ //arrived at castle
                c.setInventory(c.getInventory()+this->getBag());
                this->setBag(0);
                setState(stopped);
                VisitedFarm = false;
            }
            else if(this->location.distance(c.getLocation()) <= speed){
                this->setLocation(c.getLocation());
            }
            else{
                this->location.setRadius(speed,direction);
            }

        }

    }
    else{
        Agent::update();
    }

}
    


void Peasant::attack() {
    setBag(ZERO);
}

uint Peasant::getBag() const {
    return bag;
}

void Peasant::setBag(uint bag) {
    Peasant::bag = bag;
}

void Peasant::start_working(const string &farm_src, const string &castle_dest) {
    setFarm(farm_src);
    setCastle(castle_dest);
    setDirection(location.angle(Model::getInstance().findMapObjectByName(farm_src)->getLocation()));
    VisitedFarm = false;
    setState(Working); // add matching checks to Agent::print().
}

void Peasant::setFarm(const string &point) {
    this->farm = point;
}

void Peasant::setCastle(const string &point) {
    this->castle = point;
}

void Peasant::print() {
    if(getState()==Working ){
        string type = typeid(*this).name();
        type = type.substr(1,type.length()-1);
        if (!VisitedFarm){
            if(this->location.distance(Model::getInstance().findMapObjectByName(farm)->getLocation()) != 0){
                cout<< type <<" "<< this->getName()<< " at " << this->location << ", Heading to "<< farm<< ", speed "  << to_string(speed)<<" km/h"<<endl;
            }
            else{
                cout<< type <<" "<< this->getName()<<",  Working at "<<farm<<endl;
            }
        }
        else{
            if(this->location.distance(Model::getInstance().findMapObjectByName(castle)->getLocation()) != 0){
                cout<< type <<" "<< this->getName()<< " at " << this->location << ", Heading to "<< castle<< ", speed " << to_string(speed)<<" km/h"<<endl;
            }
            else{
                cout<< type <<" "<< this->getName()<<",  Working at "<<castle<<endl;
            }
        }
        return;
    }
    Agent::print();
}



