//
// Created by evyat on 7/8/2020.
//

#include "AgentFactory.h"


#include "Thug.h"
#include "Knight.h"
#include "Controller.h"
#include "Model.h"
#include "Peasant.h"

using namespace std;
/***********************************************************************private methods ******************************************************************************/
AgentFactory::AgentFactory() {}

AgentFactory::~AgentFactory() {}
/***********************************************************************public methods ******************************************************************************/
AgentFactory& AgentFactory::getInstance()
{
    return instance;
}
shared_ptr<Agent> AgentFactory::createAgent(std::vector<std::string> &arg)
{
   // if(Model::getInstance().existInTheMap(arg[2]))throw Controller::ErrorIllegalCommand(); //  or anything else that represents an error
    const string type=arg[1];
    // the arg vector look like this [name, type, location as a point]
    if(type=="Peasant") {//the second argument in the vector is a file name for truck the vector = ["Truck",string::file name of truck file]
        Point p(Point::parseX(arg[2]), Point::parseY(arg[2]));
        return shared_ptr<Agent>(new Peasant(arg[0], p));
    }
    if(type=="Thug"){//the arg vector look like this ["Chopper",string::name,string::point]
        Point p(Point::parseX(arg[2]),Point::parseY(arg[2]));
        return shared_ptr<Agent>(new Thug(arg[0],p));
    }
    if(type=="Knight"){
        if(Model::getInstance().existInTheMap(arg[2]))
            return shared_ptr<Agent>(new Knight(arg[0],Model::getInstance().findMapObjectByName(arg[2])->getLocation()));
        //Throw Controller::SomeException
    }
    return nullptr;
}

