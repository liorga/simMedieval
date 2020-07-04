//
// Created by lior on 04/07/2020.
//

#ifndef EX3_SIMMEDIEVAL_PEASANT_H
#define EX3_SIMMEDIEVAL_PEASANT_H


#include "Agent.h"

class Peasant : public Agent{
private:

public:
    Peasant( const string& name = "",const Point& location = Point(0,0),int speed = PEASANT_SPEED, int health = PEASANT_HEALTH);
    virtual ~Peasant();

    Point& getLocation() override;
    void update() override;
    void start_working();

};

#endif //EX3_SIMMEDIEVAL_PEASANT_H
