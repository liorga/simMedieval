//
// Created by Evyatar Bhalker & Lior Gal on 7/6/2020.
//

#ifndef EX3_SIMMEDIEVAL_THUG_H
#define EX3_SIMMEDIEVAL_THUG_H


#include "Agent.h"

class Thug : public Agent {
public:
    Thug(const string& name,const Point& location,int speed,int health = THUG_HEALTH);
    virtual ~Thug();

    void update() override;

    uint getAttackRange() const;

    void setAttackRange(uint attackRange);

    void attack();

private:
    uint attackRange;
    float speed;
};


#endif //EX3_SIMMEDIEVAL_THUG_H
