//
// Created by lior on 04/07/2020.
//

#ifndef EX3_SIMMEDIEVAL_KNIGHT_H
#define EX3_SIMMEDIEVAL_KNIGHT_H


#include "Agent.h"

class Knight : public Agent{
public:
    Knight(const string& name,const Point& location, int speed = KNIGHT_SPEED, int health = KNIGHT_LIFE);
    virtual ~Knight();

    void update() override;

private:

};


#endif //EX3_SIMMEDIEVAL_KNIGHT_H
