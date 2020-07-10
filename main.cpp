#include <iostream>
#include "Agent.h"
#include "Peasant.h"
#include "Thug.h"
#include "Knight.h"
#include "InputHandler.h"

int main(int argc,char* argv[]) {
    vector<shared_ptr<Structure>>& c = InputHandler::handle(argv[2]);
    for(auto& x : c ){
        cout << x->getName() << " " << x->getInventory() << endl;
    }

    vector<shared_ptr<Structure>>& f = InputHandler::handle(argv[1]);
    for(auto& x : f ){
        cout << x->getName() << " " << x->getInventory() << endl;
    }
    return 0;
}
