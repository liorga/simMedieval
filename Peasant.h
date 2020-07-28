//
// Created by lior on 04/07/2020.
//

#ifndef EX3_SIMMEDIEVAL_PEASANT_H
#define EX3_SIMMEDIEVAL_PEASANT_H
#define ZERO 0
#define MAX_BAG 5


#include <ostream>
#include "Agent.h"
#include "Model.h"

class Peasant : public Agent{
public:
    Peasant(const string& name , Point* location , int speed = PEASANT_SPEED, int health = PEASANT_HEALTH);
    virtual ~Peasant();

    uint getBag() const;
    void setBag(uint bag);
    void update() override;
    void attack() override;
    void start_working(const string& farm_src,const string& castle_dest);
    void print() override;


private:
	bool VisitedFarm;
	string farm;
	string castle;
    uint bag; // used to know how much is the peasant inventory(maximum 5 on his back).
    void setFarm(const string &point);

    void setCastle(const string &point);
};

#endif //EX3_SIMMEDIEVAL_PEASANT_H
