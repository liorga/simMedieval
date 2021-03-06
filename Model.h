//
// Created by Evyatar Bhalker & Lior Gal on 7/6/2020.
//

#ifndef EX3_SIMMEDIEVAL_MODEL_H
#define EX3_SIMMEDIEVAL_MODEL_H


#include <unordered_map>
#include <map>
#include <queue>
#include <memory>
#include "View.h"
#include "Farm.h"
#include "Castle.h"
#include "AgentFactory.h"
#include "Knight.h"

typedef unsigned int uint;

class Model{
public:
    enum COMMANDS{STATUS,CREATE,COURSE,POSITION,DESTINATION,ATTACK,STOPPED,START_WORKING};//commands from the controller to the model
    Model(Model &&) = delete;
    Model(Model &) = delete;
    Model &operator=(Model &&) = delete;
    Model &operator=(const Model &) = delete;
    ~Model();

    static Model& getInstance();
    void addMapObjects(const std::vector<std::shared_ptr<SimObject>>&);
    uint getTime() const;
    std::shared_ptr<SimObject> findMapObjectByName(std::string) const;//return a pointer to map object or null if this object dose not exist
    Castle& getClosestCastle(const string& k);
    bool existInTheMap(std::string) const;//receive a of an object and return true if it is in the map
    void addCommand(COMMANDS,const std::vector<std::string>& arg);//add command to the queue, the arguments are already cheacked and confirmed
    View& getView();
    void _go();//go over the commands queue and apply all the commands
    void status() const;
	void clear();

private:
    std::map<std::string,std::string> nameANDtype;//name and type of all the objects in the map
    std::unordered_multimap<std::string,std::shared_ptr<SimObject>> mapObjects;//the string is the type of the object - might change collection
    std::queue<std::pair<Model::COMMANDS,std::vector<std::string>>> commands;//commands from the controller, run them when the controller call go.
    //every item in the queue contain the type of the command and the command arguments if exist
    View view;
    uint time = 0;
    AgentFactory& factory;
    Model();
    bool SuccessfulAttack(const Point&) const;//return true if there is no police in 10km radius from the point
    void addToMap(const std::shared_ptr<SimObject>&);
    std::string getMapObjectType(const std::shared_ptr<SimObject>&) const;//return the string of that map object's name
    std::vector<std::shared_ptr<SimObject>> copyAllMapObject();
    void updateView();
    void create(std::vector<std::string>&);//the vector look like this [name of Agent,type of Agent,point or Site to start from]
    void course(const std::vector<std::string>&);//if it is a Knight/Peasant -> arg.size()=3 (curse,name,angle) and it is a Thug -> arg.size()=4 (curse,name,angle,speed)
    void position(const std::vector<std::string>&);
    void destination(const std::vector<std::string>& arg);
    bool attack(const std::vector<std::string>& arg);//return true if the attack succeeded
    void stopped(const std::string& arg);
    void start_working(const std::vector<std::string>& arg);
   

};


#endif //EX3_SIMMEDIEVAL_MODEL_H
