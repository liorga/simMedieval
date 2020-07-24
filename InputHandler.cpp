//
// Created by lior on 10/07/2020.
//

#include <sstream>
#include "InputHandler.h"

InputHandler::InputHandler() = default;

InputHandler::~InputHandler() = default;

vector<shared_ptr<SimObject>>& InputHandler::handle(string filename) {
    if(filename.compare("farms.dat") == 0){
        return InputHandler::handleFarm(filename);
    }
    if(filename.compare("castles.dat") == 0){
        return InputHandler::handleCastle(filename);
    } else{
        throw WrongFileExcption();
    }
}


vector<shared_ptr<SimObject>>& InputHandler::handleFarm(string farms_file) {
    vector<shared_ptr<SimObject>>* farms = new vector<shared_ptr<SimObject>>();
    ifstream in(farms_file);
    string line;
    string my_str;
    while(getline(in,line)){
        vector<string> result;
        stringstream s_stream(line); //create string stream from the string
        while(s_stream.good()) {
            string substr;
            getline(s_stream, substr, ','); //get first string delimited by comma
            result.push_back(substr);
        }
        string name = result[0];
        string point = "";
        point += result[1];
        point += ' ';
        point += ',';
        point += result[2];
        uint inventory = stoi(result[3]);
        uint rate = stoi(result[4]);
        //cout << "farm data: " << name << " " << point << " " << inventory << " " << rate << endl;
        shared_ptr<Farm> farm(new Farm(result[0],Point(Point::parseX(point),Point::parseY(point)),inventory,rate));
        farms->push_back(farm);
    }
    return *farms;
}


vector<shared_ptr<SimObject>>& InputHandler::handleCastle(string castles_file) {
    vector<shared_ptr<SimObject>>* castles = new vector<shared_ptr<SimObject>>();
    ifstream in(castles_file);
    string line;

    while(getline(in,line)){
        vector<string> result;
        stringstream s_stream(line); //create string stream from the string
        while(s_stream.good()) {
            string substr;
            getline(s_stream, substr, ','); //get first string delimited by comma
            result.push_back(substr);
        }
        string name = result[0];
        string point = "";
        point += result[1];
        point += ' ';
        point += ',';
        point += result[2];
        uint inventory = stoi(result[3]);
        //cout << point << endl;
        //cout << "castle data: " << name << " " << point << " " << inventory << endl;
        shared_ptr<Castle> castle(new Castle(result[0],Point(Point::parseX(point),Point::parseY(point)),inventory));
        castles->push_back(castle);
    }
    return *castles;
}

