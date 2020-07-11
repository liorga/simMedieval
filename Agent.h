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
#define MAX_BOXES 5

#include "SimObject.h"
#include "Moving_Object.h"

class Agent : public SimObject , private Moving_Object{
private:
    uint health;
    string state;
public:
    Agent(const Point& location, int speed, const string& name, int health);

    virtual ~Agent();

    int getHealth() const;
    void setHealth(int health);
    const string& getState() const;
    void setState(const string& state);

    Point& getLocation();
    void setLocation();
    void move_to();
    virtual void update() = 0;


    /*Actions*/
    void stop();
    void destination(const Point& p);
    void course();
    void attack();


    Agent& operator++();
    Agent& operator--();

    ostream &operator<<(ostream &os, const SimObject &object) override;
};


#endif //EX3_SIMMEDIEVAL_AGENT_H
