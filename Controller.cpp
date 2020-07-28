//
// Created by Evyatar Bhalker & Lior Gal on 7/6/2020.
//

#include "Controller.h"
#include "Peasant.h"
#include "Thug.h"
#include "InputHandler.h"

using namespace std;

/**************************************************************** private methods *******************************************************************/

vector<string> Controller::getDataFromCin(){ // get string from the user and break it down to a vector of substrings and returns it.
    vector<string> tmp;
    string line;
    string temp1;
    getline(cin,line); // read line from user
    string::iterator b=line.begin();
    string::iterator e=line.end();
    while (b!=e)
    {
        while (b!=e && *b!=' '){ //ignoring commas and spaces
            temp1+=*b;
            b++;
        }
        if(*(b-1)==','){
            b++;
            continue;
        }
        tmp.push_back(temp1); // puts the sub strings in vector
        temp1.clear();

        if(b==e) return tmp;
        b++;
    }
    return tmp;
}
/***************************************************************/
void Controller::PrintLineInTheBegin()
{
    cout<<"Time "<<Model::getInstance().getTime()<<" : Enter command: ";
}


/**************************************************************** public methods *******************************************************************/

Controller::Controller(){}
/****************************************************/
Controller::~Controller(){}
/***************************************************/
void Controller::go()
{
    Model::getInstance()._go();
}
/****************************************************/
void Controller::show()
{
    Model::getInstance().getView()._show(cout<<setprecision(2)); // showing the map
}
/****************************************************/
void Controller::stop(vector<string>& temp)
{
    Model::getInstance().addCommand(Model::STOPPED,temp);
}

/****************************************************/
void Controller::Default()
{
    Model::getInstance().getView()._default(); // returns the map to its default parameters
}

void Controller::size(string& s)
{
    string temp;
    string::iterator b=s.begin();
    string::iterator e=s.end();
    for(;b!=e && isdigit(*b);temp+=*b,b++);
    if(b!=e) throw ErrorException("Invalid input.");
    if(stoi(temp)<6 || stoi(temp)>30 ) throw ErrorException("size must be between 6 and 30");
    Model::getInstance().getView()._size(stoi(temp));
}

void Controller::zoom(string& s)
{
    string temp;
    string::iterator b=s.begin();
    string::iterator e=s.end();
    for(;b!=e && isdigit(*b);temp+=*b,b++);
    if(b!=e) throw ErrorException("Invalid input.");
    if(stoi(temp)<=0) throw ErrorException("map scale must be positive.");
    Model::getInstance().getView()._zoom(stoi(temp));
}
/****************************************************/
void Controller::pan(vector<std::string>& temp)
{ //change the map origin to a specific point
    if(temp.size()!=3)  throw ErrorException("illegal number of arguments");;
    string x,y;
    string::iterator b=temp[1].begin();
    string::iterator e=temp[1].end();
    for(;b!=e && (isdigit(*b)||*b =='-');x+=*b,b++);
    if(b!=e) throw ErrorException("X coordinate is invalid.");
    b=temp[2].begin();
    e=temp[2].end();
    for(;b!=e && (isdigit(*b)||*b =='-');y+=*b,b++);
    if(b!=e) throw ErrorException("Y coordinate is invalid.");
    Point tmp(stoi(x),stoi(y));
    Model::getInstance().getView()._pan(tmp);
}
/***************************************************/
void Controller::status()
{
    Model::getInstance().status();
}
/****************************************************/
void Controller::create(vector<string>& temp)
{
    if(Model::getInstance().existInTheMap(temp[1]))throw ErrorException("Agent already exists");
    if(temp[1] != "Knight" && temp[1] != "Thug" && temp[1] != "Peasant")throw ErrorException(temp[1]+"is not an Agent type!");
    Model::getInstance().addCommand(Model::CREATE,temp);
}
/****************************************************/
void Controller::attack(vector<string>& temp)
{
    if(temp.size()!=3)throw ErrorException("illegal number of arguments");

    if(!Model::getInstance().existInTheMap(temp[0]) ||typeid(*Model::getInstance().findMapObjectByName(temp[0])).name()!= typeid(Thug).name())
        throw ErrorException("Thug "+ temp[0]+" does not exist, or is not a Thug at all.");

    if(!Model::getInstance().existInTheMap(temp[2])|| ( (Model::getInstance().existInTheMap(temp[2]) && (typeid(*Model::getInstance().findMapObjectByName(temp[2])).name()!= typeid(Peasant).name()))))
        throw ErrorException("Peasant " + temp[2] + " does not exist, or is not a Peasant at all.");

    Model::getInstance().addCommand(Model::ATTACK,temp);

}
/****************************************************/
void Controller::start_working(const vector<string>& temp) {
    if(!Model::getInstance().existInTheMap(temp[0])) throw Controller::ErrorException(temp[0]+" does not exist");
    if(!Model::getInstance().existInTheMap(temp[2])) throw Controller::ErrorException(temp[2]+" does not exist");
    if(!Model::getInstance().existInTheMap(temp[3])) throw Controller::ErrorException(temp[3]+" does not exist");
    Model::getInstance().addCommand(Model::START_WORKING,temp);
}
/****************************************************/
void Controller::course(vector<string>& temp)
{
    Model::getInstance().addCommand(Model::COURSE,temp);
}
/****************************************************/
void Controller::position(vector<string>& temp)
{
    Model::getInstance().addCommand(Model::POSITION,temp);
}
/****************************************************/
void Controller::destination(vector<string>& temp)
{
    if((!(Model::getInstance().existInTheMap(temp[2])))) throw ErrorException("Castle "+temp[2]+" does not exist.");
    Model::getInstance().addCommand(Model::DESTINATION,temp);
}
/****************************************************/
void Controller::Init(int argc, char *argv[])
{
    string temp;
    try{
        if (argc != 3) throw ErrorException("illegal number of arguments");
        for (int i = 1; i < argc; i++)
        {
            temp=argv[i];
            Model::getInstance().addMapObjects(InputHandler::handle(temp)); //read structures from the file.
        }
    }
    catch (ErrorException& e)
    {
        e.PrintError();
        exit(1);
    }
    
    Run();

}


/****************************************************/
void Controller::Run() //running the simulation
{
    vector<string> line;
    while (true){
        try{
            PrintLineInTheBegin();
            line=getDataFromCin();
            if(line.size()==0) throw ErrorException("no arguments has entered");
            if(line.size()==1){
                if(line[0]=="exit") {
                    cout<<"\nGoodbye"<<endl;
                    exit(1);
                }
                if(line[0]=="go") {
                    go();
                    continue;
                }
                if(line[0]=="show") {
                    show();
                    continue;}
                if(line[0]=="default") {
                    Default();continue;}
                if(line[0]=="status") {
                    status();
                    continue;
                }
                throw  ErrorException("invalid command");
            }
            if(line.size()==2){
                if(line[0]=="size") {
                    size(line[1]);
                    continue;
                }
                if(line[0]=="zoom") {
                    zoom(line[1]);
                    continue;
                }
                
                throw  ErrorException("invalid command");
            }
            if(line[0]=="pan") {
                pan(line);
                continue;
            }
            if(line[0]=="create"){
                line.erase(line.begin());
                create(line);
                continue;
            }
            if(line[1]=="course"){
                course(line);
                continue;
            }
            if(line[1]=="position"){
                position(line);
                continue;
            }
            if(line[1]=="attack"){
                attack(line);
                continue;
            }
            if(line[1]=="stop") {
                stop(line);
                continue;
            }
            if(line[1]=="destination") {
                destination(line);
                continue;
            }
            if(line[1]=="start_working"){
                start_working(line);
                continue;
            }
            throw  ErrorException("invalid command");
        }
        catch (ErrorException& e)
        {
            e.PrintError();
        }
    }
}

