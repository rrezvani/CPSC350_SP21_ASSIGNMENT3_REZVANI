#include "FileProcessor.h"

FileProcessor::FileProcessor()
{

}

FileProcessor::~FileProcessor()
{

}

int FileProcessor::GetRows(string inputFile)
{
  inFS.open(inputFile); //opening our input file

  getline(inFS, fileSentence); //reading in the first line which is the rows
  rowsHolder = fileSentence; //setting a temporary string equal to it
  rows = stoi(rowsHolder); //setting rows equal to our string value after we convert it to an int

  return rows; //returning rows
}

int FileProcessor::GetColumns(string inputFile)
{
  getline(inFS, fileSentence); //reading the next line which is the columns
  columnsHolder = fileSentence;  //setting a temporary string equal to it
  columns = stoi(columnsHolder); //setting columns equal to our string value after we convert it to an int

  return columns; //returning columns
}

char** FileProcessor::GetArray(string inputFile) {
  fileArray = new char*[rows];
  for (int i = 0; i < rows; ++i) {
      fileArray[i] = new char[columns];
  } //creating an empty 2d array
  getline(inFS, fileSentence); //reading in the next line which is the first line of the grid
  while(!inFS.fail()) //running until there is nothing left in the file
  {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        fileArray[i][j] = fileSentence[j]; //setting our empty array equal to the characters one by one
      }
      getline(inFS, fileSentence); //reading in the next line
    }
  }
  inFS.close(); //close the input file

  return fileArray; //returning the 2d array
}
