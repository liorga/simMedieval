//
// Created by lior on 04/07/2020.
//

#ifndef EX3_SIMMEDIEVAL_PEASANT_H
#define EX3_SIMMEDIEVAL_PEASANT_H
#define ZERO 0


#include <ostream>
#include "Agent.h"

class Peasant : public Agent{
public:
    Peasant(const string& name , Point* location , int speed = PEASANT_SPEED, int health = PEASANT_HEALTH);
    virtual ~Peasant();

    uint getBag() const;
    void setBag(uint bag);
    void update() override;
    void attack() override;
    void start_working(const Point& farm_src,const Point& castle_dest);


private:
    Point farm;
    Point castle;
    bool VisitedFarm;
    uint bag; // used to know how much is the peasant inventory(maximum 5 on his back).
    void setFarm(const Point &point);

    void setCastle(const Point &point);
};

#endif //EX3_SIMMEDIEVAL_PEASANT_H
