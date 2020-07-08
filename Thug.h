//
// Created by lior on 04/07/2020.
//

#ifndef EX3_SIMMEDIEVAL_THUG_H
#define EX3_SIMMEDIEVAL_THUG_H


#include "Agent.h"

class Thug : public Agent {
public:
    Thug(const string& name = "",const Point& location = Point(0,0) , int health = THUG_HEALTH);
    virtual ~Thug();

    void update() override;
    Point& getLocation() override;

    void attack();

private:

};


#endif //EX3_SIMMEDIEVAL_THUG_H
