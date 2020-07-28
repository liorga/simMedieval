//
// Created by Evyatar Bhalker & Lior Gal on 7/6/2020.
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
    enum State{stopped, dead, Moving, pos, desti,Working};
    uint health;
    State state;
    double speed;
    double direction;
    Point* dest;

public:
    Agent(  const string& name, Point location,int speed, int health);

    virtual ~Agent();

    int getHealth() const;
    void setHealth(int health);
    const Agent::State getState() const;
    void setState(State s);
    void setDirection(double direction);
    void move_to();
    virtual void update();
    void setSpeed(double s);
    void advance(const Point& dst);
    /*Actions*/
    void stop();
    void course();
    virtual void destination(const string& SiteName);
    virtual void attack();
    void position(const Point& p);

    void print() override;


    Agent& operator++();
    Agent& operator--();
	
	
	double getDirection();
};


#endif //EX3_SIMMEDIEVAL_AGENT_H
