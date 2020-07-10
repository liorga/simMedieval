#include <iostream>
#include "Agent.h"
#include "Peasant.h"
#include "Thug.h"
#include "Knight.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Agent* ap = new Peasant("eviya");
    Agent* at = new Thug(12,"lior");
    Agent* ak = new Knight("sir mixAlot",Point(1.2,2.3));
    cout << ap->getName() << endl;
    cout << at->getName() << endl;
    cout << ak->getName() << endl;
    return 0;
}
