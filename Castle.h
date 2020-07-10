//
// Created by lior on 04/07/2020.
//

#ifndef EX3_SIMMEDIEVAL_CASTLE_H
#define EX3_SIMMEDIEVAL_CASTLE_H


#include "Structure.h"

class Castle : public Structure{

public:
    Castle(const string& name, const Point& location,uint inventory);
    virtual ~Castle();
    void update() override;

private:


};


#endif //EX3_SIMMEDIEVAL_CASTLE_H
