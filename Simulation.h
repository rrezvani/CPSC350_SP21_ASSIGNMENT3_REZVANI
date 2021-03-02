#ifndef SIMULATION_H //header guard
#define SIMULATION_H

#include "Calculator.h"
#include "FileProcessor.h" //including these two headers files to make instances of their class
#include <iostream>
#include <string>

using namespace std;

class Simulation {
  public:
    Simulation();
    ~Simulation();
    void PrintInfo();

  private:
    Calculator *calculator;
    FileProcessor *fileProcessor; //creating two instances of the classes
    int userInput;
    int rows;
    int columns;
    int sleepTime;
    double popDense;
    string userResponse;
    string fileInput;
    string fileOutput;
    char** simArray;
    char sleepAnswer;
    void FileModeDeterminer();
    void ConsoleModeDeterminer();

};

#endif
