#ifndef ARRAY_CREATOR_H
#define ARRAY_CREATOR_H

#include <iostream>
#include "Simulation.h"

using namespace std;

class ArrayCreator {
  public:
    ArrayCreator();
    ArrayCreator(int rows, int columns);
    ~ArrayCreator();
    void DetermineStartingLocations();
    int ClassicModeCalculator();

  private:
    int rows;
    int columns;
    int numLocations;
    double randomNum;
    char** myArray;
};

#endif
