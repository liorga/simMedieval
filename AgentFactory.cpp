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
    static AgentFactory instance;
    return instance;
}
shared_ptr<Agent> AgentFactory::createAgent(std::vector<std::string> &arg)
{
    if(Model::getInstance().existInTheMap(arg[2]) ){
        string typeA = typeid(*(Model::getInstance().findMapObjectByName(arg[2]))).name();
        if(typeA.substr(1,typeA.length()-1) != "Castle")
            throw Controller::IllegalCommandError();
    }  //  or anything else that represents an error
    const string type=arg[1];// the arg vector look like this [Agent name, Agent type, location]
    if(type=="Peasant")//the second argument in the vector is a
        return shared_ptr<Agent>(new Peasant(arg[0], new Point(Point::parseX(arg[2]),Point::parseY(arg[2]))));
    if(type=="Thug")//the arg vector look like this ["Thug",string::name,string::point]
        return shared_ptr<Agent>(new Thug(arg[0],Point(Point::parseX(arg[2]),Point::parseY(arg[2])),0));
    if(type=="Knight")
    {
        Point p(Model::getInstance().findMapObjectByName(arg[2])->getLocation());
        return shared_ptr<Agent>(new Knight(arg[0],p));
    }
    return nullptr;

}

