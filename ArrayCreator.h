#ifndef ARRAY_CREATOR_H //header guard
#define ARRAY_CREATOR_H

#include <iostream>

using namespace std;

class ArrayCreator {
  public:
    ArrayCreator(); //default constructor
    ArrayCreator(int rows, int columns); //overload constructor
    ~ArrayCreator(); //destructor
    char** GetArray();
    int** GetNumbers();
    double** GetDouble(); //methods that are explained in the .cpp files

  private:
    int rows;
    int columns;
    char** myArray;
    double** doubleArray;
    int** myCurrentGen; //private variables and methods that will never be called outside the class
    int GetRows();
    int GetColumns();

};

#endif
