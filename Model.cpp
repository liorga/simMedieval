//
// Created by evyat on 7/6/2020.
//

#include "Model.h"

Model::~Model() {

}

Model &Model::getInstance() {
    Model m;
    return m;
}

void Model::addMapObjects(const vector<std::shared_ptr<SimObject>> &) {

}

uint Model::getTime() const {
    return 0;
}

std::shared_ptr<SimObject> Model::findMapObjectByName(std::string) const {
    return std::shared_ptr<SimObject>();
}

Castle &Model::getClosestCastle(const Point &) const {
    Castle m;
    return m;
}

bool Model::existInTheMap(std::string) const {
    return false;
}

void Model::addCommand(Model::COMMANDS, const vector<std::string> &arg) {

}

View &Model::getView() {
    View v;
    return v;
}

void Model::_go() {

}

void Model::status() const {

}

Model::Model() {

}

bool Model::SuccessfulAttack(const Point &) const {
    return false;
}

void Model::addToMap(const shared_ptr<SimObject> &) {

}

std::string Model::getMapObjectType(const shared_ptr<SimObject> &) const {
    return std::__cxx11::string();
}

std::vector<std::shared_ptr<SimObject>> Model::copyAllMapObject() {
    return std::vector<std::shared_ptr<SimObject>>();
}

void Model::updateView() {

}

void Model::create(vector<std::string> &) {

}

void Model::course(const vector<std::string> &) {

}

void Model::position(const vector<std::string> &) {

}

void Model::destination(const vector<std::string> &arg) {

}

bool Model::attack(const vector<std::string> &arg) {
    return false;
}

void Model::stopped(const string &arg) {

}

const Point &Model::FindWarehouse(const string &) const {
    return <#initializer#>;
}
