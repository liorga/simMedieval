//
// Created by lior on 07/07/2020.
//

#ifndef EX3_SIMMEDIEVAL_VIEW_H
#define EX3_SIMMEDIEVAL_VIEW_H
#define DEFAULT_MAP_SIZE 25

typedef unsigned int uint;

class View {
public:
    View();
    virtual ~View();



private:
    char** world_map;
    double scale;
    uint size;

};


#endif //EX3_SIMMEDIEVAL_VIEW_H
