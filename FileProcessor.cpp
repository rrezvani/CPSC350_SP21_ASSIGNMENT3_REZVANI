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

  getline(inFS, fileSentence);
  rowsHolder = fileSentence;
  rows = stoi(rowsHolder);

  return rows;
}

int FileProcessor::GetColumns(string inputFile)
{
  getline(inFS, fileSentence);
  columnsHolder = fileSentence;
  columns = stoi(columnsHolder);

  return columns;
}

char** FileProcessor::GetArray(string inputFile) {
  fileArray = new char*[rows];
  for (int i = 0; i < rows; ++i) {
      fileArray[i] = new char[columns];
  }
  getline(inFS, fileSentence);
  while(!inFS.fail()) //running until there is nothing left in the file
  {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        fileArray[i][j] = fileSentence[j];
      }
      getline(inFS, fileSentence);
    }
  }
  inFS.close(); //close the input file

  return fileArray;//close the output file
}
