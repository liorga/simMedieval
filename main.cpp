#include <iostream>
#include "Agent.h"
#include "Peasant.h"
#include "Thug.h"
#include "Knight.h"

int main() {
    std::string num("(4.5,3.5");
    cout << "X value is:    " <<Point::parseX(num)<< endl;
    cout << "Y value is:    " <<Point::parseY(num)<< endl;
    return 0;
}
