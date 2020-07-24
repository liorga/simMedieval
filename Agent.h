//
// Created by lior on 04/07/2020.
//

#ifndef EX3_SIMMEDIEVAL_AGENT_H
#define EX3_SIMMEDIEVAL_AGENT_H
#define PEASANT_HEALTH 10
#define THUG_HEALTH 5
#define PEASANT_SPEED 5
#define KNIGHT_SPEED 10
#define KNIGHT_LIFE 1000
#define DEGREES 360
#define MAX_BOXES 5

#include <memory>
#include <ostream>
#include "SimObject.h"


class Agent : public SimObject {
protected:
    enum State{stopped, dead, Moving};
    uint health;
    State state;
    double speed;
    double direction;
    Point dest;

public:
    Agent(  const string& name, Point location,int speed, int health);

    virtual ~Agent();

    int getHealth() const;
    void setHealth(int health);
    const Agent::State getState() const;
    void setState(State s);
    void setDirection(double direction);
    void move_to();
    virtual void update() = 0;
    void setSpeed(double s);

    /*Actions*/
    void stop();
    void course();

    virtual void attack();
    void position(const Point& p);


    Agent& operator++();
    Agent& operator--();



};


#endif //EX3_SIMMEDIEVAL_AGENT_H
