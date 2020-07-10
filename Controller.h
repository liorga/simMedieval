//
// Created by evyat on 7/8/2020.
//

#ifndef EX3_SIMMEDIEVAL_CONTROLLER_H
#define EX3_SIMMEDIEVAL_CONTROLLER_H


#include <iostream>
#include "Point.h"
#include "vector"
#include "Model.h"
#include "View.h"



class Controller {
private:
/*private Functions*/
    void PrintLineInTheBegin();
    std::vector<std::string> getDataFromCin();

    void Run();
/*Model Functions*/
    void status();
    void go();
    void create(std::vector<std::string>& temp);


/*View Functions*/
    void Default();
    void size(std::string& s);
    void zoom(std::string& s);
    void pan(std::vector<std::string>& temp);
    void show();

/*Agent Functions*/
    void stop(std::vector<std::string>& temp);
    void attack(std::vector<std::string>& temp);
    void course(std::vector<std::string>& temp);
    void position(std::vector<std::string>& temp);
    void destination(std::vector<std::string>& temp);
public:
/**c'tor and d'tor*/
    Controller();
    Controller(const Controller &)=default;
    Controller(Controller &&)=default;
    ~Controller();
/*Override operator*/
    Controller &operator=(Controller &&)=default;
    Controller &operator=(const Controller &)=default;
/*Functions*/
    void Init(int argc, char *argv[]);
//exception//
class NumOfArgumentsError : public std::exception{
    public:
       NumOfArgumentsError() {}
        virtual void PrintError(){
            std::cout <<"Error: Invalid number of arguments"<<std::endl;
        }
    };

class IllegalCommandError : public std::exception{
    public:
        IllegalCommandError() {}
        virtual void PrintError(){
            std::cout <<"Error: illegal Command."<<std::endl;
        }
    };
class NotInTheModelError: public std::exception{
    public:
        NotInTheModelError() {}
        virtual void PrintError(){
            std::cout <<"Error: this object is not in the simulation"<<std::endl;
        }
    };

};



#endif //EX3_SIMMEDIEVAL_CONTROLLER_H
