//
// Created by lior on 04/07/2020.
//

#ifndef EX3_SIMMEDIEVAL_CASTLE_H
#define EX3_SIMMEDIEVAL_CASTLE_H


#include "Structure.h"

class Castle : public Structure{
private:

public:
    Castle(const string& name, const Point& location);
    virtual ~Castle();
    void update() override;

};


#endif //EX3_SIMMEDIEVAL_CASTLE_H
