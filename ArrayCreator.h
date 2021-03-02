#ifndef ARRAY_CREATOR_H
#define ARRAY_CREATOR_H

#include <iostream>

using namespace std;

class ArrayCreator {
  public:
    ArrayCreator();
    ArrayCreator(int rows, int columns);
    ~ArrayCreator();
    void DetermineCells();
    char** GetArray();
    int** GetNumbers();
    double** GetDouble();

  private:
    int rows;
    int columns;
    int GetRows();
    int GetColumns();
    char** myArray;
    double** doubleArray;
    int** myCurrentGen;

};

#endif
