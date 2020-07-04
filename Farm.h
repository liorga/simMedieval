//
// Created by lior on 04/07/2020.
//

#ifndef EX3_SIMMEDIEVAL_FARM_H
#define EX3_SIMMEDIEVAL_FARM_H


#include "Structure.h"

class Farm : public Structure{
private:
    uint rate;
public:
    Farm(const string& name, const Point& location, uint rate);
    virtual ~Farm();

    uint getRate() const;
    void setRate(uint rate);

    void update() override;


};


#endif //EX3_SIMMEDIEVAL_FARM_H
