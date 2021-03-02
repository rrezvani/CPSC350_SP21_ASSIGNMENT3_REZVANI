#include "Simulation.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    srand(time(0)); //making sure that our random numbers are never the same by using a seed
    Simulation *simulation = new Simulation();
    simulation->PrintInfo(); //calling our PrintInfo method that runs the whole program
    return 0;
}
