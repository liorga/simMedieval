//
// Created by Evyatar Bhalker & Lior Gal on 7/6/2020.
//

#ifndef EX3_SIMMEDIEVAL_VIEW_H
#define EX3_SIMMEDIEVAL_VIEW_H
#define DEFAULT_MAP_SIZE 25

typedef unsigned int uint;

#include <iostream>
#include <vector>
#include <set>
#include <memory>
#include "SimObject.h"
class View{
private:
    uint window_size;
    float map_scale;
    Point map_origin;
    std::vector<std::shared_ptr<SimObject>> map_objects; //contain all the map objects that should appear in the window base on the window_size,map_scale,map_origin
    std::vector<std::shared_ptr<SimObject>> all_Objects;
    /*Functions*/
    void subset();//get only the object in the window to map_objects
    void fixMapObjects();//fix the coordinates in map objects
public:
    View();
    View(const View&)=default;
    View(View&&)=default;
    View& operator=(const View&)=default;
    View& operator=(View&&)=default;
    ~View();
    //functions
    void push(std::vector<std::shared_ptr<SimObject>>&&);//update map_objects
    void _default();//go back to default view
    void _size(uint);// change the window size
    void _zoom(float);//change the scale of the map
    void _pan(const Point&);//change map origin
    void _show(std::ostream&);//show the map in the ostream
};
#endif //EX3_SIMMEDIEVAL_VIEW_H
