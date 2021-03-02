#include "ArrayCreator.h"

ArrayCreator::ArrayCreator() {
  rows = 1; //initializing our rows and columns to 1
  columns = 1;

}

ArrayCreator::ArrayCreator(int rows, int columns) {
  this->rows = rows; //initalizing our rows and columns to whatever values were inputted
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
  delete[] myCurrentGen; //syntax to delete a 2d array that had memory dynamically allocated
}

int ArrayCreator::GetRows() {
  return rows; //method to return rows
}

int ArrayCreator::GetColumns() {
  return columns; //method to return columns
}

char** ArrayCreator::GetArray() { //method that creates a 2d array of chars of size row x columns and initializes all the cells to hyphens
  myArray = new char*[rows];
  for (int i = 0; i < rows; ++i) {
      myArray[i] = new char[columns]; //syntax to dynomically allocate memory for a 2d array
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      myArray[i][j] = '-'; //initalizing all the cells to hyphens
    }
  }
  return myArray; //returning the array
}

double** ArrayCreator::GetDouble() { //method that creates a 2d array of doubles of size row x columns and initializes all the cells to 0
  doubleArray = new double*[rows];
  for (int i = 0; i < rows; ++i) {
    doubleArray[i] = new double[columns]; //syntax to dynamically allocate memory for a 2d array
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      doubleArray[i][j] = 0; //initalizing all the cells to 0s
    }
  }
  return doubleArray; //returning the array
}

int** ArrayCreator::GetNumbers() { //method that creates a 2d array of ints of size row x columns and initializes all the cells to hyphens
  myCurrentGen = new int*[rows];
  for (int i = 0; i < rows; ++i) {
      myCurrentGen[i] = new int[columns]; //syntax to dynamically allocate memory for a 2d array
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      myCurrentGen[i][j] = 0; //initializing all the cells to 0s
    }
  }
  return myCurrentGen; //returning the array
}
