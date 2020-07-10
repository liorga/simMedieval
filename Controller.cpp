//
// Created by evyat on 7/8/2020.
//

#include "Controller.h"
#include "Peasant.h"
#include "InputHandler.h"

using namespace std;

/**************************************************************** private methods *******************************************************************/
vector<string> Controller::getDataFromCin(){
    vector<string> tmp;
    string line;
    string temp1;
    getline(cin,line);
    string::iterator b=line.begin();
    string::iterator e=line.end();
    while (b!=e)
    {
        while (b!=e && *b!=' '){
            temp1+=*b;
            b++;
        }
        if(*(b-1)==','){
            b++;
            continue;
        }
        tmp.push_back(temp1);
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
    Model::getInstance().getView()._show(cout);
}
/****************************************************/
void Controller::stop(vector<string>& temp)
{
    Model::getInstance().addCommand(Model::STOPPED,temp);
}

/****************************************************/
void Controller::Default()
{
    Model::getInstance().getView()._default();
}

void Controller::size(string& s)
{
    string temp;
    string::iterator b=s.begin();
    string::iterator e=s.end();
    for(;b!=e && isdigit(*b);temp+=*b,b++);
    if(b!=e) throw IllegalCommandError();
    if(stoi(temp)<6 || stoi(temp)>30 ) throw IllegalCommandError();
    Model::getInstance().getView()._size(stoi(temp));
}

void Controller::zoom(string& s)
{
    string temp;
    string::iterator b=s.begin();
    string::iterator e=s.end();
    for(;b!=e && isdigit(*b);temp+=*b,b++);
    if(b!=e) throw IllegalCommandError();
    if(stoi(temp)<0) throw IllegalCommandError();
    Model::getInstance().getView()._zoom(stoi(temp));
}
/****************************************************/
void Controller::pan(vector<std::string>& temp)
{
    if(temp.size()!=3)  throw IllegalCommandError();;
    string x,y;
    string::iterator b=temp[1].begin();
    string::iterator e=temp[1].end();
    for(;b!=e && isdigit(*b);x+=*b,b++);
    if(b!=e) throw IllegalCommandError();
    b=temp[2].begin();
    e=temp[2].end();
    for(;b!=e && isdigit(*b);y+=*b,b++);
    if(b!=e) throw IllegalCommandError();
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
    if(Model::getInstance().existInTheMap(temp[1]))throw IllegalCommandError();
    if(temp[2]=="Chopper"){
        Model::getInstance().addCommand(Model::CREATE,temp);
        return;
    }
    if(temp[2]=="State_trooper"&& Model::getInstance().existInTheMap(temp[3])){
        Model::getInstance().addCommand(Model::CREATE,temp);
        return;
    }
    throw IllegalCommandError();
}
/****************************************************/
void Controller::attack(vector<string>& temp)
{
    if(temp.size()!=3 || ( (Model::getInstance().existInTheMap(temp[2]) && (typeid(Model::getInstance().findMapObjectByName(temp[2])).name()!="Peasant")))) throw IllegalCommandError();
    if(typeid(*Model::getInstance().findMapObjectByName(temp[0])).name()=="Thug")
        Model::getInstance().addCommand(Model::ATTACK,temp);
    else  throw IllegalCommandError();
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
    if((!(Model::getInstance().existInTheMap(temp[2])))) throw IllegalCommandError();
    Model::getInstance().addCommand(Model::DESTINATION,temp);
}
/****************************************************/
void Controller::Init(int argc, char *argv[])
{
    string temp;
    try{
        if (argc != 3) throw NumOfArgumentsError();
        //need to initialize farms.dat and castles.dat
        for (int i = 1; i < argc; i++)
        {
            temp=argv[i];
            Model::getInstance().addMapObjects(InputHandler::handle(temp)); //read structures from the file.
        }
    }
    catch (NumOfArgumentsError& e)
    {
        e.PrintError();
        exit(1);
    }

    Run();

}
/****************************************************/
void Controller::Run()
{
    vector<string> line;
    while (true){
        try{
            PrintLineInTheBegin();
            line=getDataFromCin();
            if(line.size()==0) throw IllegalCommandError();
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
                throw  IllegalCommandError();
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
                throw  IllegalCommandError();
            }
            if(line[0]=="pan") {
                pan(line);
                continue;
            }
            if(line[0]=="create"){
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
            throw  IllegalCommandError();
        }
        catch (IllegalCommandError& e)
        {
            e.PrintError();
        }
    }
}
