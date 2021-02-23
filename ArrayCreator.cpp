#include "ArrayCreator.h"
#include "Simulation.h"

ArrayCreator::ArrayCreator() {
  rows = 1;
  columns = 1;

  myArray = new char*[rows];

  // dynamically allocate memory of size N for each row
  for (int i = 0; i < rows; i++)
      myArray[i] = new char[columns];

  // assign values to allocated memory
  for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++)
          myArray[i][j] = 'x';

          // print the 2D array
  for (int i = 0; i < rows; i++)
  {
      for (int j = 0; j < columns; j++)
          std::cout << myArray[i][j] << " ";

      std::cout << std::endl;
  }
}

ArrayCreator::ArrayCreator(int rows, int columns) {
  this->rows = rows;
  this->columns = columns;

  myArray = new char*[rows];

  // dynamically allocate memory of size N for each row
  for (int i = 0; i < rows; i++)
      myArray[i] = new char[columns];
          // print the 2D array

}

ArrayCreator::~ArrayCreator() {
  for (int i = 0; i < rows; i++)
      delete[] myArray[i];

  delete[] myArray;
}

void ArrayCreator::DetermineStartingLocations() {
  srand(time(0));
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      randomNum = ((double) rand() / (RAND_MAX));
      cout << randomNum << endl;
      if (randomNum > 0.75) {
        myArray[i][j] = 'X';
      }
      else {
        myArray[i][j] = '-';
      }
    }
  }
  for (int i = 0; i < rows; i++)
  {
      for (int j = 0; j < columns; j++)
          cout << myArray[i][j] << " ";

      cout << endl;
  }
}

int ArrayCreator::ClassicModeCalculator() {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      cout << myArray[i][j] << endl;
    }
  }
  /*for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      if (myArray[i+1][j] == 'X') {
        numLocations++;
      }
      else if (myArray[i+1][j-1] == 'X') {
        numLocations++;
      }
      else if (myArray[i+1][j+1] == 'X') {
        numLocations++;
      }
      else if (myArray[i][j+1] == 'X') {
        numLocations++;
      }
      else if (myArray[i][j-1] == 'X') {
        numLocations++;
      }
      else if (myArray[i-1][j] == 'X') {
        numLocations++;
      }
      else if (myArray[i-1][j-1] == 'X') {
        numLocations++;
      }
      else if (myArray[i-1][j+1] == 'X') {
        numLocations++;
      }
    }
  }*/
  return numLocations;
}
