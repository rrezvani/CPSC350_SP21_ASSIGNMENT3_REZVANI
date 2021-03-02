#include "ArrayCreator.h"

ArrayCreator::ArrayCreator() {
  rows = 1;
  columns = 1;

}

ArrayCreator::ArrayCreator(int rows, int columns) {
  this->rows = rows;
  this->columns = columns;
}

ArrayCreator::~ArrayCreator() {
  for (int i = 0; i < rows; i++){
      delete[] myArray[i];
      delete[] doubleArray[i];
      delete[] myCurrentGen[i];
    }
  delete[] myArray;
  delete[] doubleArray;
  delete[] myCurrentGen;
}

int ArrayCreator::GetRows() {
  return rows;
}

int ArrayCreator::GetColumns() {
  return columns;
}

char** ArrayCreator::GetArray() {
  myArray = new char*[rows];
  for (int i = 0; i < rows; ++i) {
      myArray[i] = new char[columns];
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      myArray[i][j] = '-';
    }
  }
  return myArray;
}

double** ArrayCreator::GetDouble() {
  doubleArray = new double*[rows];
  for (int i = 0; i < rows; ++i) {
    doubleArray[i] = new double[columns];
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      doubleArray[i][j] = 0;
    }
  }
  return doubleArray;
}

int** ArrayCreator::GetNumbers() {
  myCurrentGen = new int*[rows];
  for (int i = 0; i < rows; ++i) {
      myCurrentGen[i] = new int[columns];
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      myCurrentGen[i][j] = 0;
    }
  }
  return myCurrentGen;
}
