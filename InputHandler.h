//
// Created by Evyatar Bhalker & Lior Gal on 7/6/2020.
//

#ifndef EX3_SIMMEDIEVAL_INPUTHANDLER_H
#define EX3_SIMMEDIEVAL_INPUTHANDLER_H
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include "Controller.h"
#include "Farm.h"
#include "Castle.h"



class InputHandler {
public:
    InputHandler();
    virtual ~InputHandler();

    static vector<shared_ptr<SimObject>>& handle(string filename);
    static vector<shared_ptr<SimObject>>& handleFarm(string farms_file);
    static vector<shared_ptr<SimObject>>& handleCastle(string castles_file);

    class WrongFileExcption{
    public:
        WrongFileExcption(){
            printError();
        };
        virtual ~WrongFileExcption() = default;
        void printError(){
            cout << "bed file input excption" << endl;
        }
    };

private:
	vector<shared_ptr<SimObject>>* farms;

};


#endif //EX3_SIMMEDIEVAL_INPUTHANDLER_H
