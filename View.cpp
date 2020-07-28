//
// Created by lior on 07/07/2020.
//

#include "View.h"

#include <algorithm>
#include <iomanip>
using namespace std;
/***********************************************************************private methods ******************************************************************************/

void View::subset()//get only the object in the window to map_objects
{
    //max point = int(origin + size* scale -scale)
    int plusToOrigin=(map_scale*window_size) - map_scale;//the number to add origin x and y
    Point maxPoint(map_origin.getX()+plusToOrigin,map_origin.getY()+plusToOrigin);
    for(auto it:all_Objects)
    {
        if(it->getLocation()>=map_origin && it->getLocation()<=maxPoint)
            map_objects.push_back(it);
    }
}
void View::fixMapObjects()//fix the coordinates in map objects
{
    int scale=map_scale;
    for_each(map_objects.begin(),map_objects.end(),[&scale](const std::shared_ptr<SimObject>& a){
        auto pair=a->getLocation().get();
        pair.first+=(pair.first <0)?(int)((-1)*pair.first) % scale:-((int)pair.first % scale);
        pair.second+=(pair.second <0)?(int)((-1)*pair.second) % scale:-((int)pair.second % scale);
        a->setLocation(Point(pair.first,pair.second));
    });
}

/***********************************************************************public methods ******************************************************************************/
View::View():window_size(DEFAULT_MAP_SIZE),map_scale(2),map_origin(0,0),map_objects(),all_Objects(){}

void View::push(vector<shared_ptr<SimObject>>&& vec){//update map_objects
    all_Objects.clear();
    all_Objects=vec;
}
void View::_default(){//go back to default view
    window_size=DEFAULT_MAP_SIZE; map_scale=2;map_origin=Point(0,0);
}
void View::_size(uint size)// change the window size
{
    window_size=size;
}
void View::_zoom(float z)//change the scale of the map
{
    map_scale=z;
}
void View::_pan(const Point& p)//change map origin
{
    map_origin=p;
}
void View::_show(std::ostream& out)//show the map in the ostream
{
    //_pan(Point(0,0));
    map_objects.clear();
    subset();
    fixMapObjects();
    sort(map_objects.begin(),map_objects.end(),[](const std::shared_ptr<SimObject>& a,const std::shared_ptr<SimObject>& b){
        return a->getLocation().getX()<b->getLocation().getX();
    });
    stable_sort(map_objects.begin(),map_objects.end(),[](const std::shared_ptr<SimObject>& a,const std::shared_ptr<SimObject>& b){
        return a->getLocation().getY()>b->getLocation().getY();
    });
    auto end=unique(map_objects.begin(),map_objects.end(),[](const std::shared_ptr<SimObject>& a,const std::shared_ptr<SimObject>& b){
        return a->getLocation().getX()==b->getLocation().getX() && a->getLocation().getY()==b->getLocation().getY();
    });
    map_objects.resize(distance(map_objects.begin(),end));
    auto it=map_objects.begin();
    out <<"Display size: "<<window_size<<", scale: "<<map_scale<<", origin:"<<map_origin<<endl;

    int maxY=map_origin.getY()+(map_scale*window_size) - map_scale, maxX=map_origin.getX()+(map_scale*window_size) - map_scale;
    for(int y=maxY,line=0;y>=map_origin.getY();y-=map_scale,line++){
	    (!((window_size-line-1)%3))? out<<setw(4)<<y<<" " : out<<setw(5)<<" ";//print the line number or space
        for(int x=map_origin.getX();x<=maxX;x+=map_scale){
            if((it!=map_objects.end()) && ((*it)->getLocation() == Point(x,y))){//if there is any object in this point
                out<<(*it)->getName().substr(0,2);
                it++;
            }
            else
                out<<". ";
        }
        out<<endl;
    }
    for(int i=map_origin.getX(),num=0;i<=maxX;i+=map_scale,num++)
        if(num%3==0)
            out<<setw(6)<<i;
    out<<endl;
}

View::~View() {

}
