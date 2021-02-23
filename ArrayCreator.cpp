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
  CurrentGen = new int*[rows];

  // dynamically allocate memory of size N for each row
  for (int i = 0; i < rows; i++) {
      myArray[i] = new char[columns];
      CurrentGen[i] = new int[columns];
    }
          // print the 2D array

}

ArrayCreator::~ArrayCreator() {
  for (int i = 0; i < rows; i++)
      delete[] myArray[i];

  delete[] myArray;
}

void ArrayCreator::DetermineStartingLocations() {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      randomNum = ((double) rand() / (RAND_MAX));
      if (randomNum > 0.75) {
        myArray[i][j] = 'X';
      }
      else {
        myArray[i][j] = '-';
      }
      CurrentGen[i][j] = j;
    }
  }
  for (int i = 0; i < rows; i++)
  {
      for (int j = 0; j < columns; j++) {
        //cout << myArray[i][j] << endl;
        cout << myArray[i][j];
      }

      cout << endl;
  }

}

int ArrayCreator::ClassicModeCalculator() {
  /*for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {

    }
  }*/

  for (int i = 1; i < rows - 1; ++i) {
    for (int j = 1; j < columns - 1; ++j) {
      cout << i << " " << j << endl << myArray[i][j] << endl;
      cout << CurrentGen[i][j] << endl;
      if (myArray[i+1][j] == 'X') {
        numLocations++;
        cout << "4 box" << endl;
      }
      if (myArray[i+1][j-1] == 'X') {
        numLocations++;
        cout << "3 box" << endl;
      }
      if (myArray[i+1][j+1] == 'X') {
        numLocations++;
        cout << "5 box"<< endl;
      }
      if (myArray[i][j+1] == 'X') {
        numLocations++;
        cout << "6 box" << endl;
      }
      if (myArray[i][j-1] == 'X') {
        numLocations++;
        cout << "2 box" << endl;
      }
      if (myArray[i-1][j] == 'X') {
        numLocations++;
        cout << "8 box" << endl;
      }
      if (myArray[i-1][j-1] == 'X') {
        numLocations++;
        cout << "1 box" << endl;
      }
      if (myArray[i-1][j+1] == 'X') {
        numLocations++;
        cout << "7 box" << endl;
      }
    }
  }
  return numLocations;
}
