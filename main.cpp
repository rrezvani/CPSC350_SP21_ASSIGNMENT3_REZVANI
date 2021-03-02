#include "Simulation.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    srand(time(0));
    Simulation *simulation = new Simulation();
    simulation->PrintInfo();
    return 0;
}
