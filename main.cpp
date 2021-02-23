#include "ArrayCreator.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int rows, columns;
    cin >> rows;
    cin >> columns;
    ArrayCreator *arrayCreator = new ArrayCreator(rows, columns);
    arrayCreator->DetermineStartingLocations();
    arrayCreator->ClassicModeCalculator();
    return 0;
}
