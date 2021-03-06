//
// Created by Evyatar Bhalker & Lior Gal on 7/6/2020.
//

#ifndef EX3_SIMMEDIEVAL_KNIGHT_H
#define EX3_SIMMEDIEVAL_KNIGHT_H


#include "Agent.h"
#include "Model.h"
class Knight : public Agent{
public:
    Knight(const string& name,const Point& location, const string& cn,int speed = KNIGHT_SPEED, int health = KNIGHT_LIFE);
    virtual ~Knight();
    void setVisit();
    void update() override;
    void print() override;
    void destination(const string& SiteName) override;
    const vector<string> & getVisitedCastles() const;
    void setTour(bool val);


private:
    string castle;
	string dst;
	vector<string> visitedCastles;
	bool DoneTour;
};


#endif //EX3_SIMMEDIEVAL_KNIGHT_H
