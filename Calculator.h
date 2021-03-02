#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include "ArrayCreator.h"
#include <unistd.h>
#include <fstream>

using namespace std;

class Calculator {
  public:
    Calculator();
    Calculator(int rows, int columns);
    Calculator(int rows, int columns, char** myArray);
    ~Calculator();
    void DetermineStartingLocations(double popDense);
    void ClassicModeCalculator();
    void CreateNewGeneration();
    void MirrorModeCalculator();
    void DoughnutModeCalculator();
    void PrintToConsole();
    bool isDone();
    void OpenOut(string fileOutput);
    void PrintToFile();
    void CloseOut();
    char** GetNewArray();
    int rows;
    int columns;
    char** newArray;
    int** secondGen;
    int** firstGen;
    int** currentGen;
    double** totalNeighborCount;

  private:
    int TopLeft();
    int TopRight();
    int BottomLeft();
    int BottomRight();
    int TopRow(int j);
    int BottomRow(int j);
    int LeftSide(int i);
    int RightSide(int i);
    void EdgeCalculator();
    void CentralChunk();
    int GetNumbers(int maxNum);
    void MoveGenerationsDown();
    void IncrementTotalNeighbors();
    int M_TopLeft();
    int M_TopRight();
    int M_BottomLeft();
    int M_BottomRight();
    int M_TopRow(int j);
    int M_BottomRow(int j);
    int M_LeftSide(int i);
    int M_RightSide(int i);
    void M_EdgeCalculator();
    void D_EdgeCalculator();
    int D_TopLeft();
    int D_TopRight();
    int D_BottomLeft();
    int D_BottomRight();
    int D_TopRow(int j);
    int D_BottomRow(int j);
    int D_LeftSide(int i);
    int D_RightSide(int i);
    ofstream outFS;
    int numLocations;
    int generationNumber;
    ArrayCreator *creatorArray;

};

#endif
