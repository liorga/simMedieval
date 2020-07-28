//
// Created by evyat on 7/6/2020.
//

#include "Model.h"
#include <utility>
#include <typeinfo>
#include <algorithm>//somthing
#include <sstream>
#include <climits>
#include "Castle.h"
#include "Farm.h"
#include "Thug.h"
#include "Peasant.h"
#include "Knight.h"
#include "Controller.h"
#include <cmath>
using namespace std;
/***********************************************************************private methods ******************************************************************************/
Model::Model():nameANDtype(),mapObjects(),commands(),view(),time(0),factory(AgentFactory::getInstance()){

}

void Model::addToMap(const std::shared_ptr<SimObject>& p)//add map object use in addMapObjects
{
    string type = typeid(*p).name();
    type = type.substr(1,type.length()-1);
    cout << type << endl;
    mapObjects.emplace(type,p);
    nameANDtype.emplace(p->getName(),type);
}


string Model::getMapObjectType(const std::shared_ptr<SimObject>& p) const//return the string of that map objects
{
        return nameANDtype.find(p->getName())->second;

}

vector<shared_ptr<SimObject>> Model::copyAllMapObject()
{
    vector<shared_ptr<SimObject>> ret;
    for(auto it:mapObjects)
        ret.push_back(it.second);
    return ret;
}
void Model::updateView()
{
    for(auto tmp:mapObjects)
    {
        if(typeid(*tmp.second) == typeid(Castle)) {
            continue;
        }
        else if(typeid(*tmp.second) == typeid(Farm)){
            Farm& f=dynamic_cast<Farm&>(*tmp.second);
            f.update();
            continue;
        }
        //else is a type an Agent - should we add a vector of Agents ans seperate it from the structures?
        Agent& v=dynamic_cast<Agent&>(*tmp.second);
        v.update();
    }
    view.push(copyAllMapObject());
}


void Model::status() const// print the status of every object in the map
{
    for_each(mapObjects.begin(),mapObjects.end(),[](const pair<string,shared_ptr<SimObject>>& p){
        p.second->print();
        cout << endl;
    });
}
void Model::create(vector<string>& arg)//the vector look like this [name of agent,type of agent,point or castle to start from]
{
    addToMap(factory.createAgent(arg));
}
void Model::course(const vector<string>& arg)//if it is a  Peasant-> arg.size()=3 (name,course,angle) and it is a Thug -> arg.size()=4 (name,course,angle,speed)
{
    float direction,speed;
    Agent &gent=dynamic_cast<Agent&>(*findMapObjectByName(arg[0]));
    stringstream stream(arg[2]);
    stream>>direction;
    gent.setDirection(DEGREES-direction+90);
    if(arg.size()==4){
        stringstream temp(arg[3]);
        temp>>speed;
        gent.setSpeed(speed);
    }
    gent.course();
}
void Model::position(const vector<string>& arg)//if it is a Knight/Peasant -> arg.size()=3 (name,position,Point) and it is a Thug -> arg.size()=4 (name,position,Point,speed)
{
    float speed;
    Agent &gent=dynamic_cast<Agent&>(*findMapObjectByName(arg[0]));

    Point p(Point::parseX(arg[2]),Point::parseY(arg[2]));
    if(arg.size()==4){
        stringstream stream(arg[3]);
        stream>>speed;
        gent.setSpeed(speed);
    }
    gent.position(p);
}
void Model::destination(const vector<string>& arg)//only a Knight -> arg.size()=3 (name,destination,castle name)
{
    if(!existInTheMap(arg[0]) || !existInTheMap(arg[2])){
        throw Controller::IllegalCommandError();
        return;
    }
    Knight &sir=dynamic_cast<Knight&>(*findMapObjectByName(arg[0]));
    sir.position(findMapObjectByName(arg[2])->getLocation());
}

void Model::stopped(const string& arg){
    Agent &gent=dynamic_cast<Agent&>(*findMapObjectByName(arg));
    gent.stop();
}

bool Model::SuccessfulAttack(const Point& p) const//return true if there is no knights in 10km radius from the point
{
    auto knights = mapObjects.find("Knight");//return all the Knights in the map
    while(knights!=mapObjects.end())
    {
        Point tmp_p=(knights->second->getLocation());
        if(p.distance(tmp_p)<=2.5) // might change according to scale
            return false;
        //how to iterate through all the knights in map/the area?
    }
    return true;
}


bool Model::attack(const vector<string>& arg)// arg=[Thug name,"attack",Peasant name]
{
    Thug &t=dynamic_cast<Thug&>(*findMapObjectByName(arg[0]));
    Peasant &p=dynamic_cast<Peasant&>(*findMapObjectByName(arg[2]));
    t.stop();
    --p;
    if((t.getAttackRange()<(t.getLocation().distance(p.getLocation())) || !(SuccessfulAttack(t.getLocation())))){
        --t;
        return false;
    }
    ++t;
    p.attack();
    return true;
}

/***********************************************************************public methods ******************************************************************************/

Model& Model::getInstance()
{
    static Model model;
    return model;
}

Model::~Model(){}

void Model::addMapObjects(const vector<shared_ptr<SimObject>>& objects)
{
    for(auto p:objects)
        addToMap(p);
    view.push(copyAllMapObject());
}

bool Model::existInTheMap(string str) const//receive a of an object and return true if it is in the map
{
    return (nameANDtype.find(str)!=nameANDtype.end());
}

shared_ptr<SimObject> Model::findMapObjectByName(string str) const//return a pointer to map object or null if this object dose not exist
{
    if(!existInTheMap(str))
        return nullptr;
    string type = nameANDtype.find(str)->second;
    auto res=find_if(mapObjects.find(type),mapObjects.end(),[&str](const pair<string,shared_ptr<SimObject>>& a)->bool{
        return (!str.compare(a.second->getName()));
    });
    return res->second;
}

unsigned int Model::getTime() const
{
    return time;
}

Castle& Model::getClosestCastle(const Point &p) const{
    pair<shared_ptr<SimObject>,float> minDis(shared_ptr<SimObject>(),UINT_MAX);
    auto tmp=mapObjects.find("Castle");
    while(tmp!=mapObjects.end())
    {
        Point tmp_p=(tmp->second->getLocation());
        double dist = p.distance(tmp_p);
        if(dist<minDis.second){
            minDis.first=(tmp->second);
            minDis.second=dist;
        }
        tmp++;
    }
    return dynamic_cast<Castle&>(*minDis.first);
}




void Model::addCommand(Model::COMMANDS c,const vector<string>& arg)//add commend to the queue
//assuming the command and all the arguments are ok
{
    commands.emplace(pair<Model::COMMANDS,vector<string>>(c,arg));
}

View& Model::getView()
{
    return view;
}

void Model::_go()
{
    time++;
    while(!commands.empty())
    {
        auto pair = commands.front();
        auto command = pair.first;
        switch (command)
        {
            case Model::STATUS:
                status();
                break;
            case Model::CREATE:
                create(pair.second);
                break;
            case Model::COURSE:
                course(pair.second);
                break;
            case Model::POSITION:
                position(pair.second);
                break;
            case Model::DESTINATION:
                destination(pair.second);
                break;
            case Model::ATTACK:
                attack(pair.second);
                break;
            case Model::STOPPED:
                stopped(pair.second[0]);
                break;
            case Model::START_WORKING:
                start_working(pair.second);
                break;

        }
        commands.pop();
    }
    updateView();
}

void Model::start_working(const vector<std::string> &arg) {
    Peasant &p=dynamic_cast<Peasant&>(*findMapObjectByName(arg[0])); //get the objects by name
    Farm &f = dynamic_cast<Farm&>(*findMapObjectByName(arg[2]));
    Castle &c = dynamic_cast<Castle&>(*findMapObjectByName(arg[3]));

    p.start_working(f.getName(),c.getName());

}
