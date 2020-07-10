//
// Created by lior on 04/07/2020.
//

#ifndef EX3_SIMMEDIEVAL_PEASANT_H
#define EX3_SIMMEDIEVAL_PEASANT_H
#define ZERO 0


#include "Agent.h"

class Peasant : public Agent{
public:
    Peasant( const string& name = "",const Point& location = Point(0,0),int speed = PEASANT_SPEED, int health = PEASANT_HEALTH);
    virtual ~Peasant();

    uint getBeg() const;
    void setBeg(uint beg);
    Point& getLocation() override;
    void update() override;
    void got_attacked();
    void start_working(string farm_src,string castle_dest);


private:
    uint beg; // used to know how much is the peasant invantory(maximum 5 on his back).
};

#endif //EX3_SIMMEDIEVAL_PEASANT_H
