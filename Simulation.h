#ifndef SIMULATION_H
#define SIMULATION_H

#include "Calculator.h"
#include "FileProcessor.h"
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
    int userInput;
    string userResponse;
    int rows;
    int columns;
    double popDense;
    FileProcessor *fileProcessor;
    string fileInput;
    string fileOutput;
    char** simArray;
    char sleepAnswer;
    int sleepTime;
    void FileModeDeterminer();
    void ConsoleModeDeterminer();

};

#endif
