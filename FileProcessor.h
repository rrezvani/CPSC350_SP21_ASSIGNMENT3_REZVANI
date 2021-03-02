#ifndef FILE_PROCESSOR_H //header guard
#define FILE_PROCESSOR_H

#include <fstream> //including a file stream
#include <iostream>
#include <string>

using namespace std;

class FileProcessor
{
  public:
    FileProcessor();
    ~FileProcessor();
    char** GetArray(string inputFile);
    int GetRows(string inputFile);
    int GetColumns(string inputFile);

  private:
    ifstream inFS; //input file stream
    ofstream outFS; //output file stream
    string fileSentence;
    string rowsHolder;
    string columnsHolder;
    int rows;
    int columns;
    char** fileArray;

};

#endif
