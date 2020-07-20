//
// Created by lior on 04/07/2020.
//

#ifndef EX3_SIMMEDIEVAL_STRUCTURE_H
#define EX3_SIMMEDIEVAL_STRUCTURE_H


#include "SimObject.h"



class Structure : public SimObject{
public:
    Structure(const string& name, const Point& location,uint inventory);
    virtual ~Structure();


    void setLocation(const Point& location);
    uint getInventory() const;
    void setInventory(uint inventory);

    Point& getLocation() override;
    virtual void update() = 0;
    void deposit();
    uint withdraw();

    ostream &operator<<(ostream &os, const SimObject &object) override;

protected:
    uint inventory;
};


#endif //EX3_SIMMEDIEVAL_STRUCTURE_H
